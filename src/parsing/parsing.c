/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:40:58 by bastienverdie     #+#    #+#             */
/*   Updated: 2024/09/16 11:49:24 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

char	**ft_duptab(char **src, char **dest, int len)
{
	int	i;

	i = 0;
	dest = ft_calloc(sizeof(char *), len + 2);
	if (!dest)
		return (NULL);
	while (i <= len - 1)
	{
		dest[i] = ft_strdup(src[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	add_line_to_map(t_data *data, char *line, int *i, int *capacity)
{
    if (*i >= *capacity)
    {
        *capacity *= 2;
        char **new_map = ft_calloc(*capacity, sizeof(char *));
        if (!new_map)
            return (1);
        for (int j = 0; j < *i; j++)
            new_map[j] = data->map[j];
        free(data->map);
        data->map = new_map;
    }
    data->map[*i] = ft_strdup(line);
    if (!data->map[*i])
        return (1);
    (*i)++;
    return (0);
}

int init_map(t_data *data)
{
    char *line;
    int i = 0;
    int capacity = 1;

    line = get_next_line(data->fd);
    if (!line)
        return (1);
    data->map = ft_calloc(capacity, sizeof(char *));
    if (!data->map)
        return (1);
    while (line)
    {
        if (ft_strlen(line) && line[ft_strlen(line) - 1] == '\n')
            line[ft_strlen(line) - 1] = '\0';
        if (ft_strlen(line) > 0 && add_line_to_map(data, line, &i, &capacity))
            return (1);
        free(line);
        line = get_next_line(data->fd);
    }
	close(data->fd);
    data->map[i] = NULL;
    return (0);
}

int is_map_closed(t_data *data, int rows, int cols)
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
					return (1);
				else if (data->flood_fill[i][j] == '7' && ((i + 1 > rows - 1 || data->flood_fill[i + 1][j] == ' ') || (i - 1 < 0 || data->flood_fill[i - 1][j] == ' ') || (j + 1 > cols - 1 || data->flood_fill[i][j + 1]) || (j - 1 < 0 || data->flood_fill[i][j - 1])))
					return (1);
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
			{
				ft_printf("Error\nInvalid character/s in the map\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_is_closed(t_data *data, int rows, int cols)
{
	int	i;
	int	j;

	cols = 0;
	rows = 0;
	i = 0;
	while (data->map[rows])
	{
		if (ft_strlen(data->map[rows]) > (size_t)cols)
			cols = ft_strlen(data->map[rows]);
		rows++;
	}
	data->flood_fill = ft_duptab(data->map, data->flood_fill, rows);
	if (check_chars_map(data, rows, cols))
		return (1);
	while (i < rows)
	{
		j = 0;
		while (j < cols && data->flood_fill[i][j])
		{
			if (data->flood_fill[i][j] == 'N' || data->flood_fill[i][j] == 'S' || data->flood_fill[i][j] == 'E' || data->flood_fill[i][j] == 'W')
			{
				data->player_orientation = data->map[i][j];
				map_flood(data, i, j, rows, cols);
				return (is_map_closed(data, 0, 0));
			}
			j++;
		}
		i++;
	}
	ft_printf_fd(1, "Error\nPlayer not found");
	return (1);
}

int	check_map(t_data *data)
{
	if (init_map(data))
		return (1);
	if (check_map_is_closed(data, 0, 0))
		return (1);
	ft_printf("Every things is good !\n");
	return (1);
}

int do_parsing(char **argv, t_data *data)
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
