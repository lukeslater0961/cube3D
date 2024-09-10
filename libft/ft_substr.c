/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:36:08 by lslater           #+#    #+#             */
/*   Updated: 2023/11/06 10:56:03 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substring;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (len == 0)
		return (ft_calloc(1, 1));
	if (start > ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substring = malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	while (j < len && s[i + start])
	{
		substring[j] = s[i + start];
		i++;
		j++;
	}
	substring[j] = '\0';
	return (substring);
}
