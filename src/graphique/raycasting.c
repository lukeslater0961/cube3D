/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:35:12 by basverdi          #+#    #+#             */
/*   Updated: 2024/10/13 03:18:36 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	isWall(float dx, float dy, t_mlx *mlx)
{
	int	x;
	int	y;

	y = (int)dy;
	x = (int)dx;
	if (y >= 0 && y < mlx->data->rows && x >= 0 && x < mlx->data->cols)
	{
		if (mlx->data->map[y][x] == '1')
			return 1;
	}
	else
		return (1);
	return (0);
}

float	drawray(t_mlx *mlx, float rangle)
{
	float	dx;
	float	dy;
	int		maxsteps = mlx->data->cols * 16;
	int		steps = 0;
	float	current_angle;

	dx = mlx->data->ppos_x;
	dy = mlx->data->ppos_y;
	while (steps < maxsteps)
	{
		if (isWall(dx, dy, mlx))
			break ;
        //mlx_pixel_put(mlx->mlx, mlx->winmap, dx * 16, dy * 16, 0xFFFFFFFF);
		dx += 0.009 * cos(rangle);
		dy += 0.009 * sin(rangle);
		steps++;
	}
	current_angle = sqrt((dx - mlx->data->ppos_x) * (dx - mlx->data->ppos_x) + (dy - mlx->data->ppos_y) * (dy - mlx->data->ppos_y));//fix fisheye
	return (current_angle);
}
