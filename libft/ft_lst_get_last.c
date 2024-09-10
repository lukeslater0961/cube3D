/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:45:54 by lslater           #+#    #+#             */
/*   Updated: 2024/05/03 12:46:12 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*lst_get_last(void *list, size_t next_offset)
{
	void	*prev;
	void	*current;

	if (!list)
		return (NULL);
	current = list;
	while (current != NULL)
	{
		prev = current;
		current = *(void **)((char *)current + next_offset);
	}
	return (prev);
}
