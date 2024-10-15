/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:07:13 by lslater           #+#    #+#             */
/*   Updated: 2024/10/15 10:39:53 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "struct.h"

int		init_graphique(t_data *data);
void	gen_minimap(t_mlx *mlx, t_data *data);
int		clear_minimap(t_mlx *mlx);

void	move_player(t_mlx *mlx, float speed);
void	rotate_player(t_mlx *mlx, t_data *data, int	r_angle);
int		render(t_mlx *mlx);
float		drawray(t_mlx *mlx, float rangle);
int		raycasting(t_mlx *mlx);

int		init_window(t_mlx *mlx);
int		windowmap_hook(int event, void *param);
int		window_hook(int event, void *param);

#endif
