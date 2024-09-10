/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:06:55 by lslater           #+#    #+#             */
/*   Updated: 2024/09/10 09:38:54 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

static int	check_extension(char *filename)
{
	char	*extension;

	extension = ft_strnstr(filename, ".cub", ft_strlen(filename));
	ft_printf(1, "%s extension\n", extension);
	extension[ft_strlen(extension) + 1] = '\0';
	if(!extension || ft_strncmp(extension, ".cub", 4) != 0)
	{
		ft_printf(2, "filename or extension is invalid\n");
		return (1);
	}
	return (0);
}

static	int	 check_directory(char *filename)
{
	int	fd;

	fd = open(filename, O_RDWR);
	if (errno == EISDIR)
	{
		ft_printf(2, "argument is directory and not a file \n");
		return (1);
	}
	else if (fd == -1)
	{
		ft_printf(2, "file doesn't exist\n");
		return (1);
	}
	ft_printf(1, "file is left open because its valid\n");
	return (0);
}

int	check_file(char	*filename)
{
	if (check_extension(filename))
		return (1);
	if (check_directory(filename))
		return (1);
	return (0);
}

int	do_parsing(char **argv)
{
	if (check_file(argv[1]))
		return (1);
	return (0);
}
