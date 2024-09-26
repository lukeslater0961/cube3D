/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bananabread <bananabread@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:55:43 by bastienverd       #+#    #+#             */
/*   Updated: 2024/09/26 15:11:37 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	check_rgb(char **texture)
{
	char	**rgb;
	int		i;

	rgb = ft_split(texture[1], ',');
	if (!rgb)
		return (1);
	if (!rgb[1] || !rgb[2])
		return (free_tab_print_err("", rgb));
	i = 0;
	while (i < 3)
	{
		if (!ft_isallnum(rgb[i]))
			return (free_tab_print_err("", rgb));
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
			return (free_tab_print_err("", rgb));
		i++;
	}
	ft_magic_free("%2", rgb);
	return (0);
}

static int	check_textures(t_data *data)
{
	const char	*texture_prefixes[4] = {"NO", "SO", "WE", "EA"};
	char		**texture;
	int			i;

	i = 0;
	data->fd_textures = ft_calloc(sizeof(int), 4);
	if (!data->fd_textures)
		return (print_error(MALLOC));
	while (i < 4)
	{
		texture = ft_split(data->textures[i], ' ');
		if (!texture[0] || (i < 4 && ft_strncmp(texture[0], \
			texture_prefixes[i], 2)))
			return (free_tab_print_err(MISSING_COORD, texture));
		if (!ft_strncmp(texture[1], "\0", ft_strlen(texture[1])))
			return (free_tab_print_err(MISSING_TPATH, texture));
		else if (i < 4 && check_directory(texture[1], data, i))
			return (free_tab_print_err("", texture));
		i++;
		ft_magic_free("%2", texture);
	}
	return (0);
}

static int	check_colours(t_data *data)
{
	const char	*texture_prefixes[2] = {"F", "C"};
	char		**texture;
	int			i;

	i = 4;
	data->colors = ft_calloc(sizeof(char *), 3);
	if (!data->colors)
		return (print_error(MALLOC));
	while (i <= 5)
	{
		texture = ft_split(data->textures[i], ' ');
		if (!texture[0] || (ft_strncmp(texture[0], texture_prefixes[i - 4], 1)))
			return (free_tab_print_err(MISSING_COLOR, texture));
		if (check_rgb(texture))
			return (free_tab_print_err(RGB_FORMAT, texture));
		data->colors[i - 4] = ft_strdup(texture[1]);
		ft_magic_free("%2", texture);
		i++;
	}
	return (0);
}

static int	parse_textures(t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(data->fd);
	if (!line)
		return (1);
	data->textures = ft_calloc(sizeof(char *), 7);
	while (line && i <= 5)
	{
		if (!line)
		{
			free(line);
			line = get_next_line(-42);
			return (1);
		}
		if (ft_strncmp(line, "\n", 1) == 0)
		{
			free(line);
			line = get_next_line(data->fd);
			continue ;
		}
		if (ft_strlen(line) && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		data->textures[i] = ft_strdup(line);
		free(line);
		i++;
		line = get_next_line(data->fd);
	}
	data->textures[i] = NULL;
	free(line);
	if (check_textures(data) || check_colours(data))
		return (free_tab_print_err("", data->textures));
	ft_magic_free("%2", data->textures);
	return (0);
}

int	check_file_content(t_data *data)
{
	if (parse_textures(data))
		return (1);
	return (0);
}
