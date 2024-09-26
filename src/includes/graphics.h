/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:07:13 by lslater           #+#    #+#             */
/*   Updated: 2024/09/26 13:33:28 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_T
# define GRAPHICS_T

# include "struct.h"

int		init_graphique(t_data *data);
void	gen_minimap(t_mlx *mlx, t_data *data);
int		clear_minimap(t_mlx *mlx);

void	move_player(t_mlx *mlx, float y, float x);

int		init_window(t_mlx *mlx, t_data *data);
int		windowmap_hook(int event, void* param);
int		window_hook(int event, void* param);
#endif
