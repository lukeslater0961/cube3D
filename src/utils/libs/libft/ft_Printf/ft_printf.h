/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lslater <lslater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:03:03 by lslater           #+#    #+#             */
/*   Updated: 2024/04/23 10:12:14 by lslater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft.h"

int	ft_printf(int fd, const char *str, ...);
int	ft_putstrp_fd(char *str, int fd);
int	ft_putcharp_fd(char c, int fd);
int	ft_putnbrhex(unsigned int n, char *base);
int	ft_putnbr(long long n);
int	ft_test_p(void *n, char *base);
int	ft_putnbrhex_p(unsigned long int n, char *base);
#endif