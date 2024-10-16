/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:36:44 by basverdi          #+#    #+#             */
/*   Updated: 2024/10/16 18:41:22 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"
#include <stdint.h>

int	getcolor(char *colorStr)
{
	union u_color	color;
	char			**str_tmp;

	str_tmp = ft_split(colorStr, ',');
	color.a = 255;
	color.r = ft_atoi(str_tmp[0]);
	color.g = ft_atoi(str_tmp[1]);
	color.b = ft_atoi(str_tmp[2]);
	free(str_tmp);
	return (color.value);
}

int	render_wall(t_mlx *mlx, int column, float length_dir, float ray_angle)
{
	int	lineh;
	int	currenth;
	int	y;

	y = 0;
	currenth = 0;
	length_dir *= cos(mlx->data->p_angle - ray_angle);
	if (length_dir <= 0)
		lineh = WINHEIGHT;
	else
		lineh = WINHEIGHT / length_dir;
	if (lineh > WINHEIGHT)
		lineh = WINHEIGHT;
	y = (WINHEIGHT / 2) - (lineh / 2);
	while (currenth < lineh)
	{
		if (mlx->ray->orientation == 1)  // Est
			mlx_pixel_put(mlx->mlx, mlx->win, column, y + currenth, 0xFFFF0000); // Rouge
		else if (mlx->ray->orientation == 2)  // Ouest
		    mlx_pixel_put(mlx->mlx, mlx->win, column, y + currenth, 0xFF00FF00); // Vert
		else if (mlx->ray->orientation == 3)  // Sud
			mlx_pixel_put(mlx->mlx, mlx->win, column, y + currenth, 0xFF0000FF); // Bleu
		else if (mlx->ray->orientation == 4)  // Nord
			mlx_pixel_put(mlx->mlx, mlx->win, column, y + currenth, 0xFFFFFF00); // Jaune
		currenth++;
	}
	return (0);
}

int	raycasting(t_mlx *mlx)
{
	t_ray	*ray;
	float	length_dir;
	float	rangle;
	int		column;

	column = 0;
	ray = ft_calloc(sizeof(t_ray), 1);
	if (!ray)
		return (1);
	mlx->ray = ray;
	rangle = mlx->data->p_angle - PI / 6;
	render(mlx);
	while (rangle < mlx->data->p_angle + PI / 6)
	{
		length_dir = drawray(mlx, rangle);
		render_wall(mlx, column, length_dir, rangle);
		rangle += (PI / 3) / WINWIDTH;
		column++;
	}
	return (0);
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
	while (y < WINHEIGHT)
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
