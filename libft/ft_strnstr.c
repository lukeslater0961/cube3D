/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:59:21 by lslater           #+#    #+#             */
/*   Updated: 2023/11/01 17:18:47 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (! (*little))
		return ((char *)(big));
	while (i < len && big[i])
	{
		while (i + j < len && little[j] == big[i + j] && big[j])
		{
			j++;
		}
		if (little[j] == '\0' || len == 0)
			return ((char *)(big + i));
		if (ft_strlen(little) == len)
			return (NULL);
		i++;
	}
	return (0);
}
