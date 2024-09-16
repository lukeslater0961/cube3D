/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:23:51 by bastienverdie     #+#    #+#             */
/*   Updated: 2024/09/12 15:04:12 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube.h"
#include <stdio.h>


int	main(int argc, char **argv)
{
	t_data	*data;
	int	i;

	i = 0;
	if (argc == 2)
	{

		data = ft_calloc(sizeof(t_data), 1);
		do_parsing(argv, data);
		if (data->map)
		{
			while (data->map[i])
			{
				free(data->map[i]);
				i++;
			}
			free(data->map);
		}
		if (data->flood_fill)
		{
			i = 0;
			while (data->flood_fill[i])
			{
				free(data->flood_fill[i]);
				i++;
			}
			free(data->flood_fill);
		}
		free(data);
	}
	else
		ft_printf_fd(2, "not enough or too many arguments");
	return (0);
}
