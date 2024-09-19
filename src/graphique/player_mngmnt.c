/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mngmnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:27:13 by lslater           #+#    #+#             */
/*   Updated: 2024/09/19 16:08:03 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	move_player(t_mlx *mlx, int y, int x)
{
	clear_minimap(mlx);
	if ((mlx->data->ppos_y + y >= mlx->data->rows) || (mlx->data->ppos_y + y < 0))
		gen_minimap(mlx, mlx->data);
	else if ((mlx->data->ppos_x + x >= mlx->data->cols) || mlx->data->ppos_x + x < 0)
		gen_minimap(mlx, mlx->data);
	else
	{
		if (mlx->data->x_pixels < 16 && mlx->data->x_pixels > -16)
			mlx->data->x_pixels += x;
		else
		{
			mlx->data->x_pixels = 0;
			mlx->data->ppos_x += x * 2;
		}
		if (mlx->data->y_pixels < 16 && mlx->data->y_pixels > -16)
			mlx->data->y_pixels += y;
		else 
		{
			mlx->data->y_pixels = 0;
			mlx->data->ppos_y += y * 2;
		}
		ft_printf("%d, %d, %d, %d\n", mlx->data->y_pixels, mlx->data->x_pixels, mlx->data->ppos_y, mlx->data->ppos_x);
		gen_minimap(mlx, mlx->data);
	}
}
