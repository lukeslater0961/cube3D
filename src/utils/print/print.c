/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:29:32 by bastienverdie     #+#    #+#             */
/*   Updated: 2024/09/12 15:04:41 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void print_texture(t_data *data)
{
	int	i;

	i = 0;
	while (data->textures[i])
	{
		ft_printf("%s\n", data->textures[i]);
		i++;
	}
}

void print_tab(char **tab)
{
	int	i;

	i = 0;
	ft_printf("Tab :\n");
	while (tab[i])
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
	ft_printf("\n\n");
}
