/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bananabread <bananabread@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:55:43 by bastienverd       #+#    #+#             */
/*   Updated: 2024/09/12 12:03:57 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

static int	check_textures(t_data *data)
{
	const char	*texture_prefixes[4] = {"NO", "SO", "WE", "EA"};
	char		*texture;
	int			i;

	i = 0;
	while (i < 4)
	{
		texture = data->textures[i];
		if (ft_strncmp(texture, texture_prefixes[i], 2) != 0 || \
			texture[2] != ' ')
		{
			ft_printf(2, "Error\n missing coordinates\n");
			return (1);
		}
		if (texture[3] == '\0')
		{
			ft_printf(2, "Error\n missing texture path\n");
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_colours(t_data *data)
{
	if (data->textures[4][0] == 'F' && data->textures[4][1] != ' ')
	{
		ft_printf(2, "Error\n the map file colour isn't formatted properly\n");
		return (1);
	}
	else if (data->textures[5][0] == 'C' && data->textures[5][1] != ' ')
	{
		ft_printf(2, "Error\n the map file colour isn't formatted properly\n");
		return (1);
	}
	return (0);
}

static int	parse_textures(t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	while (!data->textures[5])
	{
		line = get_next_line(data->fd);
		if (!line)
			return (1);
		if (ft_strlen(line) && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (ft_strlen(line) <= 0)
			continue ;
		data->textures[i] = ft_strdup(line);
		free(line);
		i++;
	}
	print_tab(data->textures);//to be removed
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
