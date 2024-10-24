/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:36:44 by basverdi          #+#    #+#             */
/*   Updated: 2024/10/24 16:57:27 by basverdi         ###   ########.fr       */
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

void	set_wall_color(t_mlx *mlx, int currenth, int y, int column)
{
	int	north;
	int	south;
	int	east;
	int	west;

	north = mlx_get_image_pixel(mlx->mlx, "north.png", column, y + currenth);
	printf("HE::::LLLOOOOO\n");
	south = mlx_get_image_pixel(mlx->mlx, "south.png", column, y + currenth);
	east = mlx_get_image_pixel(mlx->mlx, "east.png", column, y + currenth);
	west = mlx_get_image_pixel(mlx->mlx, "west.png", column, y + currenth);
	if (mlx->ray->orientation == 1)
		mlx_pixel_put(mlx->mlx, mlx->win, column, y + currenth, north);
	else if (mlx->ray->orientation == 2)
		mlx_pixel_put(mlx->mlx, mlx->win, column, y + currenth, south);
	else if (mlx->ray->orientation == 3)
		mlx_pixel_put(mlx->mlx, mlx->win, column, y + currenth, east);
	else if (mlx->ray->orientation == 4)
		mlx_pixel_put(mlx->mlx, mlx->win, column, y + currenth, west);
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
		set_wall_color(mlx, currenth, y, column);
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
