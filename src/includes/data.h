/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bananabread <bananabread@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:22:52 by bastienverd       #+#    #+#             */
/*   Updated: 2024/09/12 11:36:42 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct s_data
{
	int		fd;
	char	**map;
	char	**flood_fill;
	char	*textures[6];
	char	player_orientation;
}		t_data;

#endif 
