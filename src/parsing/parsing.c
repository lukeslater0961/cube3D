/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:40:58 by bastienverdie     #+#    #+#             */
/*   Updated: 2024/10/19 14:56:45 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	set_values(t_data *data)
{
	data->rows = 0;
	data->cols = 0;
	while (data->map[data->rows])
	{
		if (ft_strlen(data->map[data->rows]) > (size_t)data->cols)
			data->cols = ft_strlen(data->map[data->rows]);
		data->rows++;
	}
	if (data->rows * data->cols >= 360000)
		return (print_error(MAP_BIG));
	data->flood_fill = ft_duptab(data->map, data->flood_fill,
			data->rows, data->cols);
	if (check_chars_map(data, data->rows, data->cols))
		return (1);
	return (0);
}

int	check_map_is_closed(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (set_values(data))
		return (1);
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols && data->flood_fill[i][j])
		{
			if (data->flood_fill[i][j] == 'N' || data->flood_fill[i][j] == 'S'
			|| data->flood_fill[i][j] == 'E' || data->flood_fill[i][j] == 'W')
			{
				data->player_orientation = data->map[i][j];
				data->ppos_y = i;
				data->ppos_x = j;
				flood_loop(data, i, j);
				return (is_map_closed(data, data->rows, data->cols));
			}
			j++;
		}
		i++;
	}
	return (print_error(NO_PLAYER));
}

static	void	get_p_angle(t_data *data)
{
	if (data->player_orientation == 'N')
		data->p_angle = (-PI) / 2;
	else if (data->player_orientation == 'S')
		data->p_angle = -(3 * PI) / 2;
	else if (data->player_orientation == 'E')
		data->p_angle = 0;
	else if (data->player_orientation == 'W')
		data->p_angle = PI;
}

int	check_map(t_data *data)
{
	if (init_map(data))
		return (1);
	if (check_map_is_closed(data))
		return (1);
	get_p_angle(data);
	return (0);
}

int	do_parsing(char **argv, t_data *data)
{
	if (check_file(argv[1], data))
		return (1);
	if (check_file_content(data))
	{
		close(data->fd);
		return (1);
	}
	if (check_map(data))
	{
		close(data->fd);
		return (1);
	}
	return (0);
}
