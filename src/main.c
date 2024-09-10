/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:23:51 by bastienverdie     #+#    #+#             */
/*   Updated: 2024/09/10 16:32:21 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		data = ft_calloc(sizeof(t_data), 1);
		do_parsing(argv, data);
	}
	else
		ft_printf(2, "not enough or too many arguments");
	return (0);
}
