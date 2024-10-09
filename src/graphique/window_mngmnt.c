/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_mngmnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:04:55 by lslater           #+#    #+#             */
/*   Updated: 2024/10/09 17:35:41 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	init_window(t_mlx *mlx, t_data *data)
{
	mlx->winmap = mlx_new_window(mlx->mlx, data->cols * WIDTH,
			data->rows * HEIGHT, "miniMap");
	gen_minimap(mlx, data);
	mlx->win = mlx_new_window(mlx->mlx, 500, 500, "love, death and robots");
	render(mlx);
	return (0);
}

int	windowmap_hook(int event, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (event == 0)
		mlx_loop_end(mlx->mlx);
	return (0);
}

int	window_hook(int event, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (event == 0)
		mlx_loop_end(mlx->mlx);
	return (0);
}
