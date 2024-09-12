/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:52:03 by lslater           #+#    #+#             */
/*   Updated: 2024/04/05 10:30:21 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;
	char	*tmp;

	tmp = ft_calloc(1, 2);
	tmp[0] = s2[0];
	result = ft_strjoin(s1, tmp);
	free(s1);
	free(tmp);
	return (result);
}
