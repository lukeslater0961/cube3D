/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_mngmnt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:03:15 by lslater           #+#    #+#             */
/*   Updated: 2024/10/01 09:43:13 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	clear_minimap(t_mlx *mlx)
{
	ft_printf(" clearing minimap\n");
	mlx_clear_window(mlx->mlx, mlx->winmap);
	return (0);
}

void draw_direction_line(t_mlx *mlx, t_data *data)
{
    int line_length = 10; // Length of the direction line
    float end_x, end_y;

    end_x = data->ppos_x + line_length * cos(data->p_angle);
    end_y = data->ppos_y + line_length * sin(data->p_angle);

    int x0 = (int)(data->ppos_x * WIDTH);
    int y0 = (int)(data->ppos_y * HEIGHT);
    int x1 = (int)(end_x * WIDTH);
    int y1 = (int)(end_y * HEIGHT);

    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (x0 != x1 || y0 != y1)
    {
        // Ensure the pixel is within bounds before drawing
        if (x0 >= 0 && x0 < mlx->data->cols * WIDTH && y0 >= 0 && y0 < mlx->data->rows * HEIGHT)
            mlx_pixel_put(mlx->mlx, mlx->winmap, x0, y0, 0xFF00FFF0); // Draw the line in green
        int e2 = err * 2;
        if (e2 > -dy)
		{
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
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
			if (data->map[count_i / HEIGHT][count_j / WIDTH] == '1')
				mlx_pixel_put(mlx->mlx, mlx->winmap, count_j, count_i, 0xFFFF0000);
			else if (data->map[count_i / HEIGHT][count_j / WIDTH] == '0' || data->map[count_i / HEIGHT][count_j / WIDTH] == 'S')
				mlx_pixel_put(mlx->mlx, mlx->winmap, count_j, count_i, 0xFFDDCC00);
			else if (data->map[count_i / HEIGHT][count_j / WIDTH] == ' ')
				mlx_pixel_put(mlx->mlx, mlx->winmap, count_j, count_i, 0xFF0000FF);
			else if (i > 0 && j > 0 && !data->map[count_i / HEIGHT][count_j / WIDTH - 1])
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
	draw_direction_line(mlx, data);
}
