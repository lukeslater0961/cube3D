/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:55:43 by bastienverdie     #+#    #+#             */
/*   Updated: 2024/09/10 17:53:03 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

static int	parse_textures(t_data *data)
{
	int	i;
	char *line;

	i = 0;
	line = NULL;
	while (i <= 6) {
		line = get_next_line(data->fd);
		ft_printf(1, "%s\n", line);
		if (!line && i != 4)
		{
			free(line);
			return (1);
		}
		if (line)
			data->textures[i] = ft_strdup(line);
		free(line);
		i++;
	}
	ft_printf(1, "%s\n", data->textures[0]);
	ft_printf(1, "%s\n", data->textures[1]);
	ft_printf(1, "%s\n", data->textures[2]);
	ft_printf(1, "%s\n", data->textures[3]);
	ft_printf(1, "%s\n", data->textures[4]);
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
