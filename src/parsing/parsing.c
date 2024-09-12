/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:40:58 by bastienverdie     #+#    #+#             */
/*   Updated: 2024/09/12 11:40:12 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

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
    data->map[i] = NULL;
	print_tab(data->map);
    return (0);
}

int	check_map_is_closed(t_data *data, int rows, size_t cols)
{
	int	i;
	size_t	j;

	cols = 0;
	rows = 0;
	i = 0;
	j = 0;
	while (data->map[rows])
	{
		if (ft_strlen(data->map[rows]) > cols)
			cols = ft_strlen(data->map[rows]);
		rows++;
	}
	while (i < rows)
	{
		while (j < cols && data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' || data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				data->player_orientation = data->map[i][j];
				map_flood(data, i, j, rows, cols);
				return (check_map_is_closed(data, 0, 0));
			}
		}
	}
	ft_printf(1, "Error\nPlayer not found");
	return (1);
}

int	check_map(t_data *data)
{
	if (init_map(data))
		return (1);
	if (check_map_is_closed(data, 0, 0))
		return (1);
	return (1);
}

int do_parsing(char **argv, t_data *data)
{
	if (check_file(argv[1], data))
		return (1);
	if (check_file_content(data))
		return (1);
	if (check_map(data))
		return (1);
	return (0);
}
