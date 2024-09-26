/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bananabread <bananabread@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:22:52 by bastienverd       #+#    #+#             */
/*   Updated: 2024/09/26 13:26:07 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_data
{
	int		fd;
	int		*fd_textures;
	char	**colors;
	char	**map;
	int		rows;
	int		cols;
	char	**flood_fill;
	char	**textures;
	char	player_orientation;
	float	ppos_y;
	float	ppos_x;
	float	x_pixels;
	float	y_pixels;
	float	p_angle;		
}			t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*winmap;
	t_data	*data;
}				t_mlx;

#endif 
