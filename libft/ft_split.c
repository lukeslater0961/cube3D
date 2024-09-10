/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luke <luke@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:31:51 by lslater           #+#    #+#             */
/*   Updated: 2023/11/07 22:34:02 by luke             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	count;
	int	i;

	i = 1;
	count = 0;
	if (!*s)
		return (count);
	if (s[0] != c)
		count++;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static char	*ft_free(char **s1)
{
	int	i;

	i = 0;
	while (s1 && s1[i])
	{
		free(s1[i]);
		i++;
	}
	free(s1);
	return (NULL);
}

int	ft_nextword(char const *(s), char c)
{
	int	next;

	next = 0;
	while (s[next] != c && s[next])
		next++;
	return (next);
}

char	**ft_insword(char const *s, char **s1, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			k = ft_nextword(s + i, c);
			s1[j] = ft_calloc(k + 1, sizeof(char));
			if (!s1)
				ft_free(s1);
			ft_strlcpy(s1[j], s + i, k + 1);
			i += k - 1;
			j++;
		}
		i++;
	}
	s1[j] = NULL;
	return (s1);
}

char	**ft_split(char const *s, char c)
{
	char	**s1;

	if (!s)
		return (NULL);
	s1 = ft_calloc((ft_count(s, c) + 1), sizeof(char *));
	if (!s1)
		return (NULL);
	ft_insword(s, s1, c);
	return (s1);
}
