/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:55:43 by bastienverdie     #+#    #+#             */
/*   Updated: 2024/09/10 20:34:22 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int test(char *str, char sep)
{
	while (*str)
	{
		if (*str != sep)
			return (1);
		str++;
	}
	return (0);
}

static int	parse_textures(t_data *data)
{
	int	i;
	char *line;

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
			continue;
		data->textures[i] = ft_strdup(line);
		free(line);
		i++;
	}
	print_tab(data->textures);
	return (0);
}

int	check_file_content(t_data *data)
{
	if (parse_textures(data))
	{
		ft_printf(2, "C'est faux");
		return (1);
	}
	return (0);
}
