/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luke <luke@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:55:41 by lslater           #+#    #+#             */
/*   Updated: 2023/11/07 14:12:28 by luke             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
		return (1 + ft_len(-n));
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_add_n(int len, int n, char *num, int sign)
{
	num[len--] = '\0';
	while (len >= 0)
	{
		num[len--] = n % 10 + '0';
		n /= 10;
	}
	if (sign == 1)
		num[++len] = '-';
	return (num);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		len;
	int		sign;

	sign = 0;
	len = ft_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		n *= -1;
		sign = 1;
	}
	num = ft_calloc(len + 1, sizeof(char));
	if (!num)
		return (NULL);
	ft_add_n(len, n, num, sign);
	return (num);
}
