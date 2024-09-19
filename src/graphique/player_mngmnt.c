/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mngmnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:27:13 by lslater           #+#    #+#             */
/*   Updated: 2024/09/19 13:25:03 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	move_player(t_mlx *mlx, int y, int x)
{
	clear_minimap(mlx);
	if ((mlx->data->ppos_y + y >= mlx->data->rows + 1) || (mlx->data->ppos_y + y < 0))
		gen_minimap(mlx, mlx->data);
	else if ((mlx->data->ppos_x + x >= mlx->data->cols + 1) || mlx->data->ppos_x + x < 0)
		gen_minimap(mlx, mlx->data);
	else
	{
		mlx->data->ppos_y += y;
		mlx->data->ppos_x += x;
		gen_minimap(mlx, mlx->data);
	}
}
