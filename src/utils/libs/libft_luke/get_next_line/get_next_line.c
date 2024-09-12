/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 23:16:19 by bastienverd       #+#    #+#             */
/*   Updated: 2023/12/14 16:18:34 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_free(char *str)
{
	free(str);
	str = NULL;
}

static int	check_end(char *buf)
{
	unsigned int	i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n' || buf[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

static char	*get_line(char *line)
{
	unsigned int	i;
	char			*stored;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (0);
	stored = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!stored)
	{
		ft_free(stored);
		stored = NULL;
	}
	line[i + 1] = '\0';
	return (stored);
}

static char	*read_line(int fd, char *buf, char *stored)
{
	char	*tmp;
	int		j;

	j = 1;
	while (j != '\0')
	{
		j = read(fd, buf, BUFFER_SIZE);
		if (j == -1)
			return (0);
		else if (j == 0)
			break ;
		buf[j] = '\0';
		if (!stored)
		{
			stored = malloc(sizeof(char));
			stored[0] = '\0';
		}
		tmp = stored;
		stored = ft_strjoin(tmp, buf);
		ft_free(tmp);
		if (check_end(buf))
			break ;
	}
	return (stored);
}

char	*get_next_line(int fd)
{
	static char	*stored;
	char		*buf;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	line = read_line(fd, buf, stored);
	ft_free(buf);
	if (!line || line[0] == '\0')
	{
		free(stored);
		stored = NULL;
		return (NULL);
	}
	stored = get_line(line);
	return (line);
}
