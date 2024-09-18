/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:04:49 by basverdi          #+#    #+#             */
/*   Updated: 2024/09/17 15:46:11 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	free_tab_print_err(char *str, char **tab)
{
	ft_magic_free("%2", tab);
	if (!str || !*str || str == NULL)
		return (1);
	return (print_error(str));
}

int	print_error(char *str)
{
	ft_printf_fd(2, "\e[0;31mError\e[0;m\n%s\n", str);
	return (1);
}
