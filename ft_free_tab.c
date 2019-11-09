/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free_tab.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebenyoub <ebenyoub@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 21:11:21 by ebenyoub     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/09 13:52:05 by ebenyoub    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char **tab, int count)
{
	count = count - 1;
	while (count >= 0)
	{
		free(tab[count]);
		count--;
	}
	free(tab);
}
