/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:40:58 by bastienverdie     #+#    #+#             */
/*   Updated: 2024/09/19 11:59:02 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

#include <stdio.h>

char	**ft_duptab(char **src, char **dest, int len, int cols)
{
	int		i;
	size_t	j;
	size_t	ncols;

	ncols = cols;
	i = 0;
	j = 0;
	dest = ft_calloc(sizeof(char *), len + 2);
	if (!dest)
		return (NULL);
	while (i <= len - 1)
	{
		dest[i] = ft_calloc(sizeof(char *), cols + 2);
		ft_strlcpy(dest[i], src[i], cols + 1);
		j = ft_strlen(src[i]);
		while (j < ncols)
		{
			dest[i][j] = '\0';
			j++;
		}
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

int	add_line_to_map(t_data *data, char *line, int *i, int *capacity)
{
	int		j;
	char	**new_map;

	j = 0;
	if (*i + 1 >= *capacity)
	{
		*capacity *= 2;
		new_map = ft_calloc(*capacity, sizeof(char *));
		if (!new_map)
			return (1);
		while (j < *i)
		{
			new_map[j] = data->map[j];
			j++;
		}
		free(data->map);
		data->map = new_map;
	}
	data->map[*i] = ft_strdup(line);
	if (!data->map[*i])
		return (1);
	(*i)++;
	data->map[*i] = NULL;
	return (0);
}

int	init_map(t_data *data)
{
	char	*line;
	int		i;
	int		capacity;

	i = 0;
	capacity = 1;
	line = get_next_line(data->fd);
	data->map = ft_calloc(capacity, sizeof(char *));
	if (!data->map)
		return (1);
	while (line)
	{
		if (ft_strlen(line) && line[ft_strlen(line) - 1] == '\n')
		{
			if (ft_strlen(line) > 1 || (i == 0 && ft_strlen(line)))
				line[ft_strlen(line) - 1] = '\0';
		}
		if (ft_strlen(line) > 0 && add_line_to_map(data, line, &i, &capacity))
			return (1);
		free(line);
		line = get_next_line(data->fd);
	}
	close(data->fd);
	return (0);
}

int	is_map_closed(t_data *data, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (data->flood_fill[i][j] == '7')
			{
				if ((i == 0 || j == 0 || i == rows - 1 || j == cols - 1) && data->flood_fill[i][j] == '7')
					return (print_error(MAP_OPEN));
				else if ((i + 1 > rows - 1 || data->flood_fill[i + 1][j] == ' ' || !data->flood_fill[i + 1][j]) || (i - 1 < 0 || data->flood_fill[i - 1][j] == ' ' || !data->flood_fill[i - 1][j]) || (j + 1 > cols - 1 || data->flood_fill[i][j + 1] == ' ' || !data->flood_fill[i][j + 1]) || (j - 1 < 0 || data->flood_fill[i][j - 1] == ' ' || !data->flood_fill[i][j - 1]))
					return (print_error(MAP_OPEN));
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_chars_map(t_data *data, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols && data->flood_fill[i][j])
		{
			if (data->flood_fill[i][j] != '1' && data->flood_fill[i][j] != '0'
					&& data->flood_fill[i][j] != 32 && data->flood_fill[i][j] != 'N'
					&& data->flood_fill[i][j] != 'S' && data->flood_fill[i][j] != 'E'
					&& data->flood_fill[i][j] != 'w')
				return (print_error(INV_CHAR));
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_is_closed(t_data *data)
{
	int	i;
	int	j;

	i = 0;
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
	data->flood_fill = ft_duptab(data->map, data->flood_fill, data->rows, data->cols);
	if (check_chars_map(data, data->rows, data->cols))
		return (1);
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols && data->flood_fill[i][j])
		{
			if (data->flood_fill[i][j] == 'N' || data->flood_fill[i][j] == 'S' || data->flood_fill[i][j] == 'E' || data->flood_fill[i][j] == 'W')
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
	print_error(NO_PLAYER);
	return (1);
}

int	check_map(t_data *data)
{
	if (init_map(data))
		return (1);
	if (check_map_is_closed(data))
		return (1);
	ft_printf("Every things is good !\n");
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
