/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:22:13 by lslater           #+#    #+#             */
/*   Updated: 2023/11/06 16:20:01 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(const char *set, const char s1)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	if (end > 0)
		end--;
	while (ft_check(set, s1[start]))
		start++;
	while (ft_check(set, s1[end]) && start != ft_strlen(s1))
		end--;
	if (end == 0 && start == 0)
		dst = ft_calloc((end - start + 1), sizeof(char));
	else
		dst = ft_calloc((end - start + 2), sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, &s1[start], end - start + 2);
	return (dst);
}
