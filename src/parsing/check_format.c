/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:48:17 by bastienverdie     #+#    #+#             */
/*   Updated: 2024/10/24 14:38:40 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	check_extension(char *filename, char *extension_name)
{
	char	*extension;

	printf("%s\n", filename);
	extension = ft_strrchr(filename, '.');
	if (extension)
		extension[ft_strlen(extension) + 1] = '\0';
	if (!extension || strcmp(extension, extension_name) != 0)
		return (print_error(FILE_INVE));
	return (0);
}

int	check_directory(char *filename, t_data *data, int type)
{
	int	fd;

	fd = open(filename, O_RDWR);
	if (errno == EISDIR)
		return (print_error(FILE_ISDIR));
	else if (fd == -1)
		return (print_error(FILE_DE));
	else if (type == -42)
		data->fd = fd;
	return (0);
}

int	check_file(char *filename, t_data *data)
{
	if (check_extension(filename, ".cub"))
		return (1);
	if (check_directory(filename, data, -42))
		return (1);
	return (0);
}
