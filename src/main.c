/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:23:51 by bastienverdie     #+#    #+#             */
/*   Updated: 2024/09/16 18:25:40 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube.h"


int	main(int argc, char **argv)
{
	t_data	*data;
	int	i;

	i = 0;
	if (argc == 2)
	{

		data = ft_calloc(sizeof(t_data), 1);
		do_parsing(argv, data);
		ft_magic_free("%2 %2", data->map, data->flood_fill);
		free(data);
	}
	else
		ft_printf_fd(2, "not enough or too many arguments");
	return (0);
}
