/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:41:37 by luke              #+#    #+#             */
/*   Updated: 2024/04/23 09:49:50 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_instances(int fd, va_list args, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += (ft_putcharp_fd(va_arg(args, int), fd));
	else if (c == 's')
		i += (ft_putstrp_fd(va_arg(args, char *), fd));
	else if (c == 'x')
		i += (ft_putnbrhex(va_arg(args, unsigned long), "0123456789abcdef"));
	else if (c == 'X')
		i += (ft_putnbrhex(va_arg(args, unsigned long), "0123456789ABCDEF"));
	else if (c == 'd' || c == 'i')
		i += (ft_putnbr(va_arg(args, int)));
	else if (c == '%')
		i += (ft_putcharp_fd('%', fd));
	else if (c == 'u')
		i += (ft_putnbrhex(va_arg(args, unsigned int), "0123456789"));
	else if (c == 'p')
		i += (ft_test_p(va_arg(args, void *), "0123456789abcdef"));
	return (i);
}

int	ft_printf(int fd, const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	len = 0;
	i = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str && str[i])
	{
		if (str[i] == '%')
		{
			len += ft_instances(fd, args, str[i + 1]);
			if (str[i + 1] != 0)
				i++;
		}
		else
			len += ft_putcharp_fd(str[i], fd);
		i++;
	}
	va_end(args);
	return (len);
}
