/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoloher <tsoloher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:09:21 by tsoloher          #+#    #+#             */
/*   Updated: 2024/05/17 15:10:05 by tsoloher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_realloc(char **envp, size_t size)
{
	char	**new;
	int		i;

	i = 0;
	new = ft_calloc(size, sizeof(char *));
	if (!new)
		return (NULL);
	while (envp[i])
	{
		new[i] = envp[i];
		i++;
	}
	return (new);
}
