/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:55:44 by mcolin            #+#    #+#             */
/*   Updated: 2026/01/09 14:58:37 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stddef.h>

inline size_t	ft_abs(int nb)
{
	return (((nb < 0) * (nb * -1)) + ((nb > 0) * nb));
}

inline char	ft_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}

inline char	ft_issign(char c)
{
	return (c == '-' || c == '+');
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	i;

	if (nmemb != 0 && !(size < ((size_t) - 1) / nmemb))
		return (NULL);
	i = nmemb * size;
	res = malloc(i);
	if (!res)
		return (NULL);
	while (i--)
		((unsigned char *)res)[i] = 0;
	return (res);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		res;
	char	cond;

	cond = 1;
	i = 0;
	res = 0;
	while (nptr[i] == ' ' || (9 <= nptr[i] && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
		cond *= -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (ft_isdigit(nptr[i]))
		res = res * 10 + nptr[i++] - '0';
	return (res * cond);
}
