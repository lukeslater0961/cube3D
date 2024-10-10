/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:35:12 by basverdi          #+#    #+#             */
/*   Updated: 2024/10/10 18:30:06 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"
int	inbounds(float dx, float dy, t_mlx *mlx)
{
	int	x;
	int	y;

	printf("inbiounds\n");
	y = mlx->data->ppos_y + dy / 16;
	x = mlx->data->ppos_x + dx / 16;

	printf("x = %i y = %i c = %c\n",x, y, mlx->data->map[y][x]);
	if (!mlx->data->map[y][x])//to bee changed
		return (1);
	return (0);
}

int	isWall(float dx, float dy, t_mlx *mlx)
{
	int	x;
	int	y;

	y = mlx->data->ppos_y + dy / 16;
	x = mlx->data->ppos_x + dx / 16;
	if (mlx->data->map[y] && mlx->data->map[y][x] && mlx->data->map[y][x] == '1')
		return (1);
	return (0);
}

void	drawray(t_mlx *mlx, float endpointx, float endpointy)
{
	float	dx;
	float	dy;

	dx = mlx->data->ppos_x;
	dy = mlx->data->ppos_y;
	while (!inbounds(dx, dy, mlx))
	{
		printf("dx: %.2f\ndy: %.2f\n, endx = %.2f, endy = %.2f\n", dx, dy, endpointx, endpointy);
		printf("drawing ray\n");
		if (isWall(dx, dy, mlx) || inbounds(endpointx, endpointy, mlx))
		{
			printf("wall hit");
			break ;
		}
		mlx_pixel_put(mlx->mlx, mlx->winmap, dx * WIDTH, dy * HEIGHT, 0xFFFFFFFF);
		dx += 0.09 * cos(mlx->data->p_angle);
		dy += 0.09 * sin(mlx->data->p_angle);
	}
}
