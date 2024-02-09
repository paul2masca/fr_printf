/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:35:57 by pde-masc          #+#    #+#             */
/*   Updated: 2024/02/09 16:39:32 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *src)
{
	if (!*src)
		return (0);
	return (1 + ft_strlen(++src));
}

char	*ft_strdup(const char *src)
{
	int		len;
	char	*dup;
	int		i;

	if (!src)
		return (NULL);
	i = 0;
	len = ft_strlen(src);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		++i;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	if (!s || (!(str = malloc(len + 1))))
		return (NULL);
	if (start > ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	while (len--)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

static size_t	count_digits(int n)
{
	if (!n)
		return (0);
	return (1 + count_digits(n / 10));
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;

	len = count_digits(n) + (n < 0) + (n == 0);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (!n)
		res[0] = '0';
	if (n < 0)
	{
		res[--len] = -1 * (n % 10) + '0';
		res[0] = '-';
		n = n / 10 * -1;
	}
	while (n)
	{
		res[--len] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}
