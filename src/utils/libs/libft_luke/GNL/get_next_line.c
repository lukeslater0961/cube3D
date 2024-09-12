/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:52:39 by luke              #+#    #+#             */
/*   Updated: 2024/01/03 12:25:06 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *buffer, int *error)
{
	int		r_size;

	r_size = read(fd, buffer, BUFFER_SIZE);
	if (r_size == -1)
	{
		*error = -1;
		free(buffer);
		return (0);
	}
	else if (r_size == 0)
	{
		*error = 1;
		free(buffer);
		return (NULL);
	}
	buffer[r_size] = 0;
	return (buffer);
}

char	*get_line(char *buffer, char *line, int *v_line)
{
	char		*size;
	int			mem_size;

	size = ft_strchr(buffer, '\n');
	mem_size = ft_strlen(&buffer[size - buffer]);
	if (size == NULL && *buffer != 0)
	{
		line = ft_strnjoin(line, buffer, ft_strlen(buffer));
	}
	else if (size != NULL && *buffer != 0)
	{
		line = ft_strnjoin(line, buffer, size - buffer + 1);
		ft_memmove(buffer, &buffer[size - buffer + 1], mem_size);
		*v_line = 1;
		return (line);
	}
	return (line);
}

char	*check_error(char *buffer, char *line, int error, int *error_msg)
{
	if (!buffer && error == 1)
	{
		if (*line != 0)
			return (line);
		*error_msg = 1;
		free(line);
		return (NULL);
	}
	if (!buffer && error == -1)
	{
		*error_msg = 1;
		free(line);
		return (NULL);
	}
	else if ((*buffer == 0) || (!buffer && line && !*line))
	{
		*error_msg = 1;
		free(line);
		free(buffer);
		return (0);
	}
	return (0);
}

char	*process_line(char **buffer, char **line, int fd)
{
	int			error;
	int			v_line;
	int			error_msg;

	error_msg = 0;
	v_line = 0;
	error = 0;
	while (*buffer && error != -1 && error != 1)
	{
		*line = get_line(*buffer, *line, &v_line);
		if (v_line != 0)
			return (*line);
		*buffer = read_line(fd, *buffer, &error);
		check_error(*buffer, *line, error, &error_msg);
		if (error_msg == 1)
			return (NULL);
	}
	if (**line && *line)
		return (*line);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0)
		return (NULL);
	if (BUFFER_SIZE < 0)
		return (NULL);
	if (buffer == NULL)
		buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	line = ft_calloc(1, 1);
	if (!line)
	{
		free(buffer);
		return (buffer);
	}
	return (process_line(&buffer, &line, fd));
}
