/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdier-  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:48:17 by bastienverdie     #+#    #+#             */
/*   Updated: 2024/09/10 17:22:04 by bastienverdie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

static int  check_extension(char *filename)
{
    char    *extension;

	extension = ft_strrchr(filename, '.');
    if (extension)
		extension[ft_strlen(extension) + 1] = '\0';
	if(!extension || strcmp(extension, ".cub") != 0)
    {
		ft_printf(2, "Error\n Filename or extension is invalid\n");
		return (1);
	}
	return (0);
}

static  int  check_directory(char *filename, t_data *data)
{
    int fd;

    fd = open(filename, O_RDWR);
    if (errno == EISDIR)
    {
        ft_printf(2, "Error\n Argument is directory and not a file \n");
        return (1);
    }
    else if (fd == -1)
    {
        ft_printf(2, "Error\n File doesn't exist\n");
        return (1);
    }
    data->fd = fd;
    return (0);
}

int check_file(char *filename, t_data *data)
{
	if (check_extension(filename))
        return (1);
	if (check_directory(filename, data))
		return (1);
	return (0);
}

