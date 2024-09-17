/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:23:51 by bastienverdie     #+#    #+#             */
/*   Updated: 2024/09/17 14:09:53 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube.h"
#include "includes/utils.h"
#include "utils/libs/libft/libft.h"


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
			ft_magic_free("%2", data->map);
		if (data->flood_fill)
			ft_magic_free("%2", data->flood_fill);
		if (data->fd_textures)
			ft_magic_free("%1", data->fd_textures);
		if (data->colors)
			ft_magic_free("%2", data->colors);
		free(data);
	}
	else
		return (print_error(ARG));
	return (0);
}
