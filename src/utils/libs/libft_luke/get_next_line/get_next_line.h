/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bananabread <bananabread@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 23:06:52 by bastienverd       #+#    #+#             */
/*   Updated: 2024/09/11 14:39:29 by bananabread      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// unsigned int	ft_strlen(const char *str);
// char			*ft_strdup(const char *s);
char			*ft_strjoin(const char *s1, const char *s2);
// char			*ft_substr(const char *s, unsigned int start, unsigned int len);
char			*get_next_line(int fd);

#endif
