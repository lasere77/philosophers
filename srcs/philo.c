/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:09:22 by mcolin            #+#    #+#             */
/*   Updated: 2026/02/23 14:52:48 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "parsing_utils.h"
#include "utils.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define MSG_ERROR_PARSING "error parsing: \
check if all variables have a positive value. \
And they does not overflow\n"

bool	set_philo_const(char *argv[], t_philo_const *philo_const)
{
	if (have_digit(argv) || have_neg_value(argv))
	{
		printf(MSG_ERROR_PARSING);
		return (1);
	}
	philo_const->nb_philo = ft_atoi(argv[1], NULL);
	philo_const->time_to_die = ft_atoi(argv[2], NULL);
	philo_const->time_to_eat = ft_atoi(argv[3], NULL);
	philo_const->time_to_sleep = ft_atoi(argv[4], NULL);
	philo_const->nb_times_philosopher_must_eat = -1;
	if (argv[5])
		philo_const->nb_times_philosopher_must_eat = ft_atoi(argv[5], NULL);
	return (0);
}

static void	set_forks(t_philo *philos)
{
	size_t	i;

	i = 0;
	while (i < (size_t)philos[0].philo_const->nb_philo)
	{
		philos[i].right_fork = &philos[
			(i + 1) % philos[0].philo_const->nb_philo
		].left_fork;
		if (philos[i].right_fork)
			philos[i].right_fork->available = true;
		philos[i].left_fork.available = true;
		pthread_mutex_init(&philos[i].left_fork.lock, NULL);
		i++;
	}
}

t_philo	*set_philos(t_simulation *simulation_state, t_philo_const *philo_const)
{
	t_philo	*philos;
	size_t	i;

	simulation_state->state_simulation = true;
	simulation_state->nb_philo_must_eat = 0;
	gettimeofday(&simulation_state->start, NULL);
	pthread_mutex_init(&simulation_state->lock, NULL);
	pthread_mutex_init(&simulation_state->lock_stdout, NULL);
	philos = ft_calloc(philo_const->nb_philo, sizeof(t_philo));
	if (!philos)
	{
		free(philo_const);
		return (NULL);
	}
	i = 0;
	while (i < (size_t)philo_const->nb_philo)
	{
		philos[i].philo_const = philo_const;
		philos[i].simulation_state = simulation_state;
		i++;
	}
	set_forks(philos);
	return (philos);
}
