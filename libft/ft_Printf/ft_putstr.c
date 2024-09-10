/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:03:22 by luke              #+#    #+#             */
/*   Updated: 2024/07/10 16:07:43 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstrp_fd(char *str, int fd)
{
	int	len;

	len = ft_strlen(str);
	if (!str)
		return (write(fd, "(null)", 6));
	write(fd, str, len);
	return (len);
}
