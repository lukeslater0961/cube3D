/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mngmnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:27:13 by lslater           #+#    #+#             */
/*   Updated: 2024/09/30 16:11:51 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

/*void	rotate_player(t_mlx *mlx, t_data *data, int	r_angle)
{
	float	old_ppos_x;

	old_ppos_x = data->ppos_x;
	printf("%f p_angle", data->p_angle);
	if (r_angle == 1)
	{
		data->ppos_x = (data->ppos_x * cos(data->p_angle) - (data->ppos_x * sin(data->p_angle)));
		data->ppos_y = (old_ppos_x * cos(data->p_angle) - (old_ppos_x * sin(data->p_angle)));
	}
	else 
	{
		data->ppos_x = (data->ppos_x * cos(data->p_angle) + (data->ppos_x * sin(data->p_angle)));
		data->ppos_y = (old_ppos_x * cos(data->p_angle) + (old_ppos_x * sin(data->p_angle)));
	}
	gen_minimap(mlx, mlx->data);
}*/

void normalize_angle(float *angle)
{
    // Normalize the angle to be in the range [0, 2π]
    while (*angle < 0)
        *angle += 2 * M_PI;
    while (*angle >= 2 * M_PI)
        *angle -= 2 * M_PI;
}

void rotate_player(t_mlx *mlx, t_data *data, int r_angle)
{
    float angle_step;
 
	clear_minimap(mlx);
	if (r_angle == 1)
		angle_step = -0.125;
	else
		angle_step = 0.125;
    data->p_angle += angle_step;
    normalize_angle(&data->p_angle);
    printf("Rotating Player: p_angle = %f\n", data->p_angle);
	gen_minimap(mlx, mlx->data);
}

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

void	move_player(t_mlx *mlx, float speed)
{
	clear_minimap(mlx);
	if ((mlx->data->ppos_y + speed > mlx->data->rows)
		|| (mlx->data->ppos_y + speed < 0))
		do_pacman(mlx, speed, speed);
	else if ((mlx->data->ppos_x + speed > mlx->data->cols)
		|| mlx->data->ppos_x + speed < 0)
		do_pacman(mlx, speed, speed);
	else
	{
		if ( mlx->data->p_angle >= 0.09 && mlx->data->p_angle <= 1.46)
		{
			speed = -speed;
			mlx->data->ppos_y += speed * cos(mlx->data->p_angle);
			mlx->data->ppos_x += speed * sin(mlx->data->p_angle);
		}
		mlx->data->ppos_y += speed * cos(mlx->data->p_angle);
		mlx->data->ppos_x += speed * sin(mlx->data->p_angle);
		gen_minimap(mlx, mlx->data);
	}
    printf("Rotating Player: p_angle = %f\n", mlx->data->p_angle);
}
