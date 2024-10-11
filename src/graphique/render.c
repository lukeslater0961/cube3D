/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:36:44 by basverdi          #+#    #+#             */
/*   Updated: 2024/10/11 18:19:33 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"
#include <stdint.h>

int	getcolor(char *colorStr)
{
	union	u_color	color;
	char	**str_tmp;

	str_tmp = ft_split(colorStr, ',');
	color.a = 255;
	color.r = ft_atoi(str_tmp[0]);
	color.g = ft_atoi(str_tmp[1]);
	color.b = ft_atoi(str_tmp[2]);
	free(str_tmp);
	return (color.value);
}

void	raycasting(t_mlx *mlx)
{
	t_ray	*ray;
	int		lenght_dir;
	float	endpointx;
	float	endpointy;
	float	rangle;

	ray = ft_calloc(sizeof(t_ray), 1);
	mlx->data->ray = ray;
	mlx->data->ray->raydiry = sin(mlx->data->p_angle);
	mlx->data->ray->raydirx = cos(mlx->data->p_angle);
	endpointx = (mlx->data->ppos_x / 16) + 1 * mlx->data->ray->raydirx;
	endpointy = (mlx->data->ppos_y / 16) + 1 * mlx->data->ray->raydiry;
	rangle = mlx->data->p_angle - PI/6;

	while (rangle < mlx->data->p_angle + PI/6)
	{
		lenght_dir = drawray(mlx, rangle);
		rangle += 0.05;
	}
}

int	render(t_mlx *mlx)
{
	int	x;
	int	y;
	int	ceiling;
	int	floor;

	y = 0;
	floor = getcolor(mlx->data->colors[0]);
	ceiling = getcolor(mlx->data->colors[1]);
	while(y < WINHEIGHT)
	{
		x = 0;
		while (x < WINWIDTH)
		{
			if (y <= WINHEIGHT / 2)
				mlx_pixel_put(mlx->mlx, mlx->win, x, y, ceiling);
			else
				mlx_pixel_put(mlx->mlx, mlx->win, x, y, floor);
			x++;
		}
		y++;
	}
	return (0);
}
