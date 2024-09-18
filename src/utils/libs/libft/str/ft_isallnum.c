/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isallnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:18:26 by basverdi          #+#    #+#             */
/*   Updated: 2024/09/17 12:21:04 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_bool	ft_isallnum(char *str)
{
	while (*str)
	{
		if (!ft_isnum(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}
