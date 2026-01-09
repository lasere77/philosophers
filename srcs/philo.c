/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:09:22 by mcolin            #+#    #+#             */
/*   Updated: 2026/01/09 15:01:16 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "parsing_utils.h"
#include "utils.h"

#include <stdio.h>

#define MSG_ERROR_PARSING "error parsing: \
check if all variables have a positive value.\n"

t_philo_const	*set_philo_const(char *argv[])
{
	t_philo_const	*philo_const;

	if (have_digit(argv) || have_neg_value(argv))
	{
		printf(MSG_ERROR_PARSING);
		return (NULL);
	}
	philo_const = malloc(sizeof(t_philo_const));
	if (!philo_const)
		return (NULL);
	philo_const->nb_philo = ft_abs(ft_atoi(argv[1]));
	philo_const->time_to_die = ft_abs(ft_atoi(argv[2]));
	philo_const->time_to_eat = ft_abs(ft_atoi(argv[3]));
	philo_const->time_to_sleep = ft_abs(ft_atoi(argv[4]));
	philo_const->nb_times_philosopher_must_eat = 0;
	if (argv[5])
	{
		philo_const->nb_times_philosopher_must_eat = ft_abs(ft_atoi(argv[5]));
		if (philo_const->nb_times_philosopher_must_eat == 0)
		{
			free(philo_const);
			return (NULL);
		}
	}
	return (philo_const);
}

static void	set_forks(t_philo *philos)
{
	size_t	i;

	i = 0;
	while (i < philos[0].philo_const->nb_philo)
	{
		philos[i].right_fork = &philos[(i + 1)
			% philos[0].philo_const->nb_philo].left_fork;
		philos[i].left_fork.available = 1;
		i++;
	}
}

t_philo	*set_philos(char **argv)
{
	t_philo_const	*philo_const;
	t_philo			*philos;
	size_t			i;

	philo_const = set_philo_const(argv);
	if (!philo_const)
		return (NULL);
	philos = ft_calloc(philo_const->nb_philo, sizeof(t_philo));
	if (!philos)
	{
		free(philo_const);
		return (NULL);
	}
	i = 0;
	while (i < philo_const->nb_philo)
	{
		philos[i].philo_const = philo_const;
		i++;
	}
	set_forks(philos);
	return (philos);
}

void	free_philos(t_philo *philos)
{
	free(philos[0].philo_const);
	free(philos);
}
