/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_mngmnt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:03:15 by lslater           #+#    #+#             */
/*   Updated: 2024/09/24 07:32:19 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	clear_minimap(t_mlx *mlx)
{
	ft_printf(" clearing minimap\n");
	mlx_clear_window(mlx->mlx, mlx->winmap);
	return (0);
}

void	gen_minimap(t_mlx *mlx, t_data *data)
{
	int	i = 0;
	int	j = 0;

	while (i < (data->rows * HEIGHT))
	{
		j = 0;
		while (j < (data->cols * HEIGHT))
		{
			if (data->map[i / HEIGHT][j / WIDTH] == '1' && i != (data->ppos_y * HEIGHT + data->y_pixels) && j != (data->ppos_x * WIDTH + data->x_pixels))
				mlx_pixel_put(mlx->mlx, mlx->winmap, j, i, 0xFFFF00FF);
			else if (data->map[i / HEIGHT][j / WIDTH] == '0' && i != (data->ppos_y * HEIGHT + data->y_pixels) && j != (data->ppos_x * WIDTH + data->x_pixels))
				mlx_pixel_put(mlx->mlx, mlx->winmap, j, i, 0xFF0C0C0C);
			else if (data->map[i / HEIGHT][j / WIDTH] == ' ' && i != (data->ppos_y * HEIGHT + data->y_pixels) && j != (data->ppos_x * WIDTH + data->x_pixels))
				mlx_pixel_put(mlx->mlx, mlx->winmap, j, i, 0xFF000000);
			else if (!data->map[i / HEIGHT][j / WIDTH])
			{
				j++;
				continue;
			}
			j++;
		}
		i++;
	}
}
