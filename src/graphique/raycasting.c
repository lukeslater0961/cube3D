/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:35:12 by basverdi          #+#    #+#             */
/*   Updated: 2024/10/16 19:02:25 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	init_dda(t_mlx *mlx, float ray_angle)
{
	mlx->ray->ray_dir_x = cos(ray_angle);
	mlx->ray->ray_dir_y = sin(ray_angle);
	mlx->ray->x = (int)(mlx->data->ppos_x);
    mlx->ray->y = (int)(mlx->data->ppos_y);
	mlx->ray->delta_dist_x = fabs(1 / mlx->ray->ray_dir_x);
    mlx->ray->delta_dist_y = fabs(1 / mlx->ray->ray_dir_y);
	if (mlx->ray->ray_dir_x < 0)
    {
        mlx->ray->step_x = -1;
        mlx->ray->side_dist_x = (mlx->data->ppos_x - mlx->ray->x) * mlx->ray->delta_dist_x;
    }
	else
    {
        mlx->ray->step_x = 1;
        mlx->ray->side_dist_x = (mlx->ray->x + 1.0 - mlx->data->ppos_x) * mlx->ray->delta_dist_x;
    }
	if (mlx->ray->ray_dir_y < 0)
    {
        mlx->ray->step_y = -1;
        mlx->ray->side_dist_y = (mlx->data->ppos_y - mlx->ray->y) * mlx->ray->delta_dist_y;
    }
	else
    {
        mlx->ray->step_y = 1;
        mlx->ray->side_dist_y = (mlx->ray->y + 1.0 - mlx->data->ppos_y) * mlx->ray->delta_dist_y;
    }
}

void	is_wall(t_mlx *mlx)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (mlx->ray->side_dist_x < mlx->ray->side_dist_y)
	    {
			mlx->ray->side_dist_x += mlx->ray->delta_dist_x;
			mlx->ray->x += mlx->ray->step_x;
	      mlx->ray->side = 0; // Hit a vertical wall
	    }
		else
	    {
	        mlx->ray->side_dist_y += mlx->ray->delta_dist_y;
	        mlx->ray->y += mlx->ray->step_y;
			mlx->ray->side = 1; // Hit a horizontal wall
	    }
        // Check if ray has hit a wall
		if (mlx->ray->y >= 0 && mlx->ray->y < mlx->data->rows - 1 && mlx->ray->x >= 0 && mlx->ray->x < mlx->data->cols - 1)
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
	//perp_wall_dist *= cos(mlx->data->p_angle - rangle);
	if (mlx->ray->side == 0)
    {
        if (mlx->ray->ray_dir_x > 0)
            mlx->ray->orientation = 1; // West wall
        else
            mlx->ray->orientation = 2; // East wall
    }
	else
    {
        if (mlx->ray->ray_dir_y > 0)
            mlx->ray->orientation = 3; // North wall
        else
            mlx->ray->orientation = 4; // South wall
    }
	return (perp_wall_dist);
}
