/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:36:44 by basverdi          #+#    #+#             */
/*   Updated: 2024/10/12 14:28:45 by lslater          ###   ########.fr       */
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

int	render_wall(t_mlx *mlx, int column, int length_dir)
{
	int	line_H;
	int	current_Height = 0;
	int	y;

	if (length_dir <= 0)
		line_H = WINHEIGHT / 3;
	else
		line_H = (WINHEIGHT) / length_dir;
	if (line_H > WINHEIGHT / 3)
		line_H = WINHEIGHT / 3;
	y = (WINHEIGHT / 2) - (line_H / 2);
	while (current_Height < line_H)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, column, y + current_Height, 0xFFFFFFFF);
		current_Height++;
	}
	printf("line height = %i\n", line_H);
	return (0);
}

int	raycasting(t_mlx *mlx)
{
	//t_ray	*ray;
	int		length_dir;
	float	rangle;
	int		column;

	column = 0;
	/*ray = ft_calloc(sizeof(t_ray), 1);
	if (!ray)
		return (1);
	mlx->data->ray = ray;
	mlx->data->ray->raydiry = sin(mlx->data->p_angle);
	mlx->data->ray->raydirx = cos(mlx->data->p_angle);*/
	rangle = mlx->data->p_angle - PI/6;
	render(mlx);
	while (rangle < mlx->data->p_angle + PI/6)
	{
		length_dir = drawray(mlx, rangle);
		render_wall(mlx, column, length_dir);
		rangle += 0.0005;
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
