/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:36:44 by basverdi          #+#    #+#             */
/*   Updated: 2024/10/08 20:47:03 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	render(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while(y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			if (y <= HEIGHT / 2)
				mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0xFF00FF00);
			else
				mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0xFFFFFFFF);
			x++;
		}
		y++;
	}
	return (1);
}
