/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphique.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:38:02 by basverdi          #+#    #+#             */
/*   Updated: 2024/09/18 14:43:36 by lslater          ###   ########.fr       */
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

int	init_window(t_mlx *mlx, t_data *data)
{
	(void)data;
	mlx->win = mlx_new_window(mlx->mlx, 500, 500, "love, death and robots");
	mlx->winmap = mlx_new_window(mlx->mlx, data->cols * WIDTH, data->rows * HEIGHT, "miniMap");
	return (0);
}

int	windowmap_hook(int event, void* param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (event == 0)	
		mlx_destroy_window(mlx->mlx, mlx->winmap);
	return (0);
}

int	window_hook(int event, void* param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (event == 0)
		mlx_loop_end(mlx->mlx);
	return (0);
}

int	keyboard_hook(int event, void* param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (event == 41)
		mlx_loop_end(mlx->mlx);
	if (event == 26)
		ft_printf("%d", event);
	if (event == 4)
		ft_printf("%d", event);
	if (event == 22)
		ft_printf("%d", event);
	if (event == 7)
		ft_printf("%d", event);
	if (event == 41)
		ft_printf("%d", event);
	if (event == 41)
		ft_printf("%d", event);
	else
		ft_printf("%d", event);
	return (0);
}

int	init_graphique(t_data *data)
{
	t_mlx	*mlx;

	print_tab(data->map);
	mlx = ft_calloc(sizeof(t_mlx), 1);
	mlx->mlx = mlx_init();
	ft_printf("%p\n", mlx->mlx);
	if (init_window(mlx, data))
		return (1);
	gen_minimap(mlx, data);
	mlx_on_event(mlx->mlx, mlx->win, MLX_WINDOW_EVENT, window_hook, mlx);
	mlx_on_event(mlx->mlx, mlx->winmap, MLX_WINDOW_EVENT, windowmap_hook, mlx);
	mlx_on_event(mlx->mlx, mlx->win, MLX_KEYDOWN, keyboard_hook, mlx);
	mlx_loop(mlx->mlx);
	if (mlx->winmap)
		mlx_destroy_window(mlx->mlx, mlx->winmap);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	return (0);
}
