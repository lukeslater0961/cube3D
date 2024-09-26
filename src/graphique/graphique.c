/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphique.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:38:02 by basverdi          #+#    #+#             */
/*   Updated: 2024/09/26 15:39:22 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	keyboard_hook(int event, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (event == 41)
		mlx_loop_end(mlx->mlx);
	if (event == 26)
		move_player(mlx, -0.125, 0);
	if (event == 4)
		move_player(mlx, 0, -0.125);
	if (event == 22)
		move_player(mlx, 0.125, 0);
	if (event == 7)
		move_player(mlx, 0, 0.125);
	else
		ft_printf("%d", event);
	return (0);
}

int	init_graphique(t_data *data)
{
	t_mlx	*mlx;

	print_tab(data->map);
	mlx = ft_calloc(sizeof(t_mlx), 1);
	if (!mlx)
		return (1);
	mlx->mlx = mlx_init();
	mlx->data = data;
	if (init_window(mlx, data))
		return (1);
	gen_minimap(mlx, data);
	mlx_on_event(mlx->mlx, mlx->win, MLX_WINDOW_EVENT, window_hook, mlx);
	mlx_on_event(mlx->mlx, mlx->winmap, MLX_WINDOW_EVENT, windowmap_hook, mlx);
	mlx_on_event(mlx->mlx, mlx->win, MLX_KEYDOWN, keyboard_hook, mlx);
	mlx_loop(mlx->mlx);
	mlx_destroy_window(mlx->mlx, mlx->winmap);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	return (0);
}
