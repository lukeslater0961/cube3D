/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_mngmnt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:03:15 by lslater           #+#    #+#             */
/*   Updated: 2024/09/26 15:15:19 by basverdi         ###   ########.fr       */
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
	float	i = 0;
	float	j = 0;
	int		count_i = 0;
	int		count_j = 0;

	printf("x: %f\n", data->ppos_x);
	while (count_i < (data->rows * HEIGHT))
	{
		count_j = 0;
		j = 0;
		while (count_j < (data->cols * WIDTH))
		{
			if (data->map[count_i / HEIGHT][count_j / WIDTH] == '1' && i != data->ppos_y && j != data->ppos_x)
				mlx_pixel_put(mlx->mlx, mlx->winmap, count_j, count_i, 0xFFFF0000);
			else if ((data->map[count_i / HEIGHT][count_j / WIDTH] == '0' || data->map[count_i / HEIGHT][count_j / WIDTH] == 'S') && i != data->ppos_y && j != data->ppos_x)
				mlx_pixel_put(mlx->mlx, mlx->winmap, count_j, count_i, 0xFFDDCC00);
			else if (data->map[count_i / HEIGHT][count_j / WIDTH] == ' ' && i != data->ppos_y && j != data->ppos_x)
				mlx_pixel_put(mlx->mlx, mlx->winmap, count_j, count_i, 0xFF0000FF);
			else if (!data->map[count_i / HEIGHT][count_j / WIDTH])
			{
				count_j++;
				continue;
			}
			count_j++;
			j += 0.125;
		}
		count_i++;
		i += 0.125;
	}
}
