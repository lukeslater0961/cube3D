/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:42:01 by lslater           #+#    #+#             */
/*   Updated: 2023/11/06 16:37:46 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_size;

	i = 0;
	if (size == 0 || dst == NULL)
		return (ft_strlen(src));
	dst_size = ft_strlen(dst);
	if (size <= dst_size)
		return (ft_strlen(src) + size);
	if (!*src)
		return (dst_size);
	while (src[i] && dst_size + i + 1 < size)
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (ft_strlen(src) + dst_size);
}
