/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_mngmnt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:03:15 by lslater           #+#    #+#             */
/*   Updated: 2024/09/19 12:03:52 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	gen_minimap(t_mlx *mlx, t_data *data)
{
	int	i = 0;
	int	j = 0;

	while (i < (data->rows * HEIGHT))
	{
		j = 0;
		while (j < (data->cols * HEIGHT))
		{
			if (data->map[i / HEIGHT][j / WIDTH] == '1')
				mlx_pixel_put(mlx->mlx, mlx->winmap, j, i, 0xFFFF00FF);
			else if (data->map[i / HEIGHT][j / WIDTH] == '0')
				mlx_pixel_put(mlx->mlx, mlx->winmap, j, i, 0xFF0C0C0C);
			else if (data->map[i / HEIGHT][j / WIDTH] == ' ')
				mlx_pixel_put(mlx->mlx, mlx->winmap, j, i, 0xFF000000);
			else if (!data->map[i / HEIGHT][j / WIDTH])
			{
				j++;
				continue;
			}
			else
				mlx_pixel_put(mlx->mlx, mlx->winmap, j, i, 0xFFFF0000);
			j++;
		}
		i++;
	}
}
