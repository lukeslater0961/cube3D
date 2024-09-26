/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mngmnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:27:13 by lslater           #+#    #+#             */
/*   Updated: 2024/09/26 15:18:21 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	do_pacman(t_mlx *mlx, float y, float x)
{
	if (mlx->data->ppos_y + y >= mlx->data->rows)
		mlx->data->ppos_y = 1.125;
	else if (mlx->data->ppos_x + x >= mlx->data->cols)
		mlx->data->ppos_x = 1.125;
	else if (mlx->data->ppos_y + y < 1)
		mlx->data->ppos_y = mlx->data->rows - 1.125;
	else if (mlx->data->ppos_x + x < 1)
		mlx->data->ppos_x = mlx->data->cols - 1.125;
	gen_minimap(mlx, mlx->data);
}

void	move_player(t_mlx *mlx, float y, float x)
{
	clear_minimap(mlx);
	if ((mlx->data->ppos_y + y > mlx->data->rows) || (mlx->data->ppos_y + y < 0))
		do_pacman(mlx, y, x);
	else if ((mlx->data->ppos_x + x > mlx->data->cols) || mlx->data->ppos_x + x < 0)
		do_pacman(mlx, y, x);
	else
	{
		mlx->data->ppos_y += y;
		mlx->data->ppos_x += x;
		printf("%.6f, %.6f, %.2f, %.2f\n", y, x, mlx->data->ppos_y, mlx->data->ppos_x);
		gen_minimap(mlx, mlx->data);
	}
}
