/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:29:32 by bastienverdie     #+#    #+#             */
/*   Updated: 2024/09/13 15:03:28 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void print_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_printf("Tab :\n");
	while (tab[i])
	{
		while (tab[i][j])
		{
			ft_printf("%c", tab[i][j]);
			j++;
		}
		ft_printf("%c", '\n');
		i++;
	}
	ft_printf("\n\n");
}
