/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebenyoub <ebenyoub@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/16 16:10:18 by ebenyoub     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/09 13:50:48 by ebenyoub    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		count_wd(char *str, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] == c || str[i] == '\0')
		{
			while (str[i] && str[i] == c)
				i++;
			nb++;
		}
		else
			i++;
	}
	return (nb);
}

static int		*word_mark(char *str, char c)
{
	int		i;
	int		a;
	int		nb;
	int		*tab;

	i = 0;
	a = 1;
	nb = count_wd(str, c);
	tab = malloc(sizeof(int) * (nb + 1));
	tab[0] = 0;
	while (str[i] && (a <= nb))
	{
		if (str[i] == c)
		{
			while (str[i] == c)
				i++;
			tab[a] = i;
			a++;
		}
		i++;
	}
	return (tab);
}

static char		*malloc_word(char *str, char c)
{
	int		i;
	int		a;
	char	*word;

	i = 0;
	a = 0;
	if (!str[0])
		return (NULL);
	while (str[i] && str[i] != c)
		i++;
	word = malloc(sizeof(char) * i);
	if (word == NULL)
		return (NULL);
	while (a < i)
	{
		word[a] = str[a];
		a++;
	}
	word[a] = '\0';
	return (word);
}

static char		**make_tab(char *str, char c)
{
	int		i;
	int		*mark;
	char	**tab;

	i = 0;
	tab = malloc(sizeof(char *) * (count_wd(str, c) + 1));
	if (tab == NULL)
		return (NULL);
	mark = malloc(sizeof(int) * count_wd(str, c));
	if (mark == NULL)
		return (NULL);
	mark = word_mark(str, c);
	while (i <= count_wd(str, c))
	{
		if (!(tab[i] = malloc_word(&str[mark[i]], c)))
			return (ft_free_tab(tab));
		i++;
	}
	tab[i] = NULL;
	free(mark);
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	char	*set;
	char	*str;
	char	**tab;

	if (s)
	{
		i = 0;
		if (!(set = malloc(sizeof(char))))
			return (NULL);
		set[0] = c;
		str = ft_strtrim(s, set);
		free(set);
		tab = make_tab(str, c);
		return (tab);
	}
	return (NULL);
}
