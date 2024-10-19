/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:35:12 by basverdi          #+#    #+#             */
/*   Updated: 2024/10/19 17:38:43 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	check_ray_dir(t_mlx *mlx)
{
	if (mlx->ray->ray_dir_x < 0)
	{
		mlx->ray->step_x = -1;
		mlx->ray->side_dist_x = (mlx->data->ppos_x - mlx->ray->x) \
			* mlx->ray->delta_dist_x;
	}
	else
	{
		mlx->ray->step_x = 1;
		mlx->ray->side_dist_x = (mlx->ray->x + 1.0 - mlx->data->ppos_x) \
			* mlx->ray->delta_dist_x;
	}
	if (mlx->ray->ray_dir_y < 0)
	{
		mlx->ray->step_y = -1;
		mlx->ray->side_dist_y = (mlx->data->ppos_y - mlx->ray->y) \
			* mlx->ray->delta_dist_y;
	}
	else
	{
		mlx->ray->step_y = 1;
		mlx->ray->side_dist_y = (mlx->ray->y + 1.0 - mlx->data->ppos_y) \
			* mlx->ray->delta_dist_y;
	}
}

void	init_dda(t_mlx *mlx, float ray_angle)
{
	mlx->ray->ray_dir_x = cos(ray_angle);
	mlx->ray->ray_dir_y = sin(ray_angle);
	mlx->ray->x = (int)(mlx->data->ppos_x);
	mlx->ray->y = (int)(mlx->data->ppos_y);
	mlx->ray->delta_dist_x = fabs(1 / mlx->ray->ray_dir_x);
	mlx->ray->delta_dist_y = fabs(1 / mlx->ray->ray_dir_y);
	check_ray_dir(mlx);
}

void	check_side(t_mlx *mlx)
{
	if (mlx->ray->side_dist_x < mlx->ray->side_dist_y)
	{
		mlx->ray->side_dist_x += mlx->ray->delta_dist_x;
		mlx->ray->x += mlx->ray->step_x;
		mlx->ray->side = 0;
	}
	else
	{
		mlx->ray->side_dist_y += mlx->ray->delta_dist_y;
		mlx->ray->y += mlx->ray->step_y;
		mlx->ray->side = 1;
	}
}

void	is_wall(t_mlx *mlx)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		check_side(mlx);
		if (mlx->ray->y >= 0 && mlx->ray->y < mlx->data->rows - 1
			&& mlx->ray->x >= 0 && mlx->ray->x < mlx->data->cols - 1)
		{
			if (mlx->data->map[mlx->ray->y][mlx->ray->x] == '1')
				hit = 1;
		}
		else
			hit = 1;
	}
}

float	drawray(t_mlx *mlx, float rangle)
{
	float	perp_wall_dist;

	init_dda(mlx, rangle);
	is_wall(mlx);
	if (mlx->ray->side == 0)
		perp_wall_dist = (mlx->ray->side_dist_x - mlx->ray->delta_dist_x);
	else
		perp_wall_dist = (mlx->ray->side_dist_y - mlx->ray->delta_dist_y);
	if (mlx->ray->side == 0)
	{
		if (mlx->ray->ray_dir_x > 0)
			mlx->ray->orientation = 1;
		else
			mlx->ray->orientation = 2;
	}
	else
	{
		if (mlx->ray->ray_dir_y > 0)
			mlx->ray->orientation = 3;
		else
			mlx->ray->orientation = 4;
	}
	return (perp_wall_dist);
}
