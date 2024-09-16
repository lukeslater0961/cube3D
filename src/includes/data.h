/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bananabread <bananabread@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:22:52 by bastienverd       #+#    #+#             */
/*   Updated: 2024/09/16 18:29:45 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct s_data
{
	int		fd;
	int		*fd_textures;
	char	**colors;
	char	**map;
	char	**flood_fill;
	char	**textures;
	char	player_orientation;
}		t_data;

#endif 
