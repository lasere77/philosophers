/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:43:29 by mcolin            #+#    #+#             */
/*   Updated: 2026/01/09 15:01:03 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_utils.h"
#include "utils.h"

bool	have_digit(char *argv[])
{
	size_t	i;
	size_t	j;
	bool	have_digit;

	i = 1;
	while (argv[i])
	{
		j = 0;
		have_digit = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
				have_digit = 1;
			j++;
		}
		if (!have_digit)
			return (1);
		i++;
	}
	return (0);
}

bool	have_neg_value(char *argv[])
{
	size_t	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) <= 0)
			return (1);
		i++;
	}
	return (0);
}
