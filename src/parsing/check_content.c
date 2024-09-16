/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bananabread <bananabread@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:55:43 by bastienverd       #+#    #+#             */
/*   Updated: 2024/09/16 18:59:22 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"
#include <fcntl.h>
#include <unistd.h>

int	check_rgb(char **texture)
{
	char	**rgb;
	int		i;

	rgb = ft_split(texture[1], ',');
	if (!rgb)
		return (1);
	if (!rgb[1] || !rgb[2])
	{
		ft_magic_free("%2", rgb);
		return (1);
	}
	i = 0;
	while (i < 3)
	{
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
		{
			ft_magic_free("%2", rgb);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_textures(t_data *data)
{
	const char	*texture_prefixes[6] = {"NO", "SO", "WE", "EA", "F", "C"};
	char		**texture;
	int			i;

	i = 0;
	data->fd_textures = ft_calloc(sizeof(int), 7);
	data->colors = ft_calloc(sizeof(char *), 3);
	texture = NULL;
	while (i <= 5)
	{
		texture = ft_split(data->textures[i], ' ');
		if (texture[i] && ((i < 4 && ft_strncmp(texture[0], texture_prefixes[i], 2)) || (i > 3 && ft_strncmp(texture[0], texture_prefixes[i], 1))!= 0 ))
		{
			ft_magic_free("%2", texture);
			ft_printf_fd(2, "Error\n missing coordinates\n");
			return (1);
		}
		if (!ft_strncmp(texture[1], "\0", ft_strlen(texture[1])))
		{
			ft_magic_free("%2", texture);
			ft_printf_fd(2, "Error\n missing texture path or color\n");
			return (1);
		}
		if (i > 3 && check_rgb(texture))
		{
			ft_magic_free("%2", texture);
			ft_printf_fd(2, "Error\n the color isn't a rgb format\n");
			return (1);
		}
		else if (i < 4 && check_directory(texture[1], data, i))
		{	
			ft_magic_free("%2", texture);
			return (1);
		}
		if (i > 3)
			data->colors[i - 4] = ft_strdup(texture[3]);
		i++;
		ft_magic_free("%2", texture);
	}
	return (0);
}

static int	check_colours(t_data *data)
{
	if (data->textures[4][0] == 'F' && data->textures[4][1] != ' ')
	{
		ft_printf_fd(2, "Error\n the map file colour isn't formatted properly\n");
		return (1);
	}
	else if (data->textures[5][0] == 'C' && data->textures[5][1] != ' ')
	{
		ft_printf_fd(2, "Error\n the map file colour isn't formatted properly\n");
		return (1);
	}
	return (0);
}

static int	parse_textures(t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(data->fd);
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
	data->textures[i] = ft_strdup("\0");
	free(line);
	if (check_textures(data) || check_colours(data))
		return (1);
	return (0);
}

int	check_file_content(t_data *data)
{
	if (parse_textures(data))
		return (1);
	return (0);
}
