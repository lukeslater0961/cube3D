/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:37:18 by luke              #+#    #+#             */
/*   Updated: 2024/04/23 09:43:42 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrhex(unsigned int n, char *base)
{
	int		i;
	size_t	b_len;

	b_len = ft_strlen(base);
	i = 0;
	if (n >= b_len)
		i += ft_putnbrhex(n / b_len, base);
	i += write(1, &base[n % b_len], 1);
	return (i);
}

int	ft_putnbrhex_p(unsigned long int n, char *base)
{
	int		i;
	size_t	b_len;

	b_len = ft_strlen(base);
	i = 0;
	if (n >= b_len)
		i += ft_putnbrhex_p(n / b_len, base);
	i += write(1, &base[n % b_len], 1);
	return (i);
}

int	ft_test_p(void *n, char *base)
{
	int	i;

	i = 0;
	if (n == 0)
		return (write(2, "(nil)", 5));
	i += write(2, "0x", 2);
	i += ft_putnbrhex_p((unsigned long long)n, base);
	return (i);
}
