/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:35:12 by basverdi          #+#    #+#             */
/*   Updated: 2024/10/15 10:57:33 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	isWall(float dx, float dy, t_mlx *mlx)
{
	int	x;
	int	y;
	float delta_y;
	float delta_x;

	y = (int)dy;
	x = (int)dx;
	if (y >= 0 && y < mlx->data->rows && x >= 0 && x < mlx->data->cols)
	{
		if (mlx->data->map[y][x] == '1')
		{
			delta_x = fabsf(dx - (int)dx);
			delta_y = fabsf(dy - (int)dy);

			if (delta_x < delta_y) 
				mlx->data->ray->orientation = 1;  // Vertical wall (X-axis)
			else if (delta_y < delta_x)
				mlx->data->ray->orientation = 2;  // Horizontal wall (Y-axis)
			else
				mlx->data->ray->orientation = 0;
			return 1;
		}
	}
	else
		return (1);
	return (0);
}

float drawray(t_mlx *mlx, float ray_angle)
{
    float length_dir = 0.0;
    float ray_x = mlx->data->ppos_x; 
    float ray_y = mlx->data->ppos_y;
    int hit_wall = 0;
    
    while (!hit_wall) {
        if (isWall(ray_x, ray_y, mlx))
		{
            hit_wall = 1;
            length_dir = sqrt((ray_x - mlx->data->ppos_x) * \
							  (ray_x - mlx->data->ppos_x) + \
							  (ray_y -  mlx->data->ppos_y) * \
							  (ray_y - mlx->data->ppos_y));
        }
		ray_x += cos(ray_angle) * 0.009;
		ray_y += sin(ray_angle) * 0.009;
    }
    return (length_dir);
}
