/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bananabread <bananabread@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:22:52 by bastienverd       #+#    #+#             */
/*   Updated: 2024/09/19 15:19:38 by lslater          ###   ########.fr       */
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
	int		ppos_y;
	int		ppos_x;
	int		x_pixels;
	int		y_pixels;
}			t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*winmap;
	t_data	*data;
}				t_mlx;


#endif 
