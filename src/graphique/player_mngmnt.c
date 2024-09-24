/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mngmnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:27:13 by lslater           #+#    #+#             */
/*   Updated: 2024/09/24 07:39:35 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	do_pacman(t_mlx *mlx, int y, int x)
{
	if (mlx->data->ppos_y + y >= mlx->data->rows)
		mlx->data->ppos_y = 1;
	else if (mlx->data->ppos_x + x >= mlx->data->cols)
		mlx->data->ppos_x = 1;
	else if (mlx->data->ppos_y + y < 1)
		mlx->data->ppos_y = mlx->data->rows - 1;
	else if (mlx->data->ppos_x + x < 1)
		mlx->data->ppos_x = mlx->data->cols - 1;
	gen_minimap(mlx, mlx->data);
}

void	move_player(t_mlx *mlx, int y, int x)
{
	clear_minimap(mlx);
	if ((mlx->data->ppos_y + y >= mlx->data->rows) || (mlx->data->ppos_y + y <= 0))
		do_pacman(mlx, y, x);
	else if ((mlx->data->ppos_x + x >= mlx->data->cols) || mlx->data->ppos_x + x <= 0)
		do_pacman(mlx, y, x);
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
