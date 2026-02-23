/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:37:36 by mcolin            #+#    #+#             */
/*   Updated: 2026/02/23 17:56:50 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_routines.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MSG_FMT "please use the format:\n./philo number_of_philosophers \
time_to_die time_to_eat time_to_sleep \
optional: [number_of_times_each_philosopher_must_eat]\n"

static void	destroy_mutex(t_philo *philos)
{
	size_t	i;

	pthread_mutex_destroy(&philos[0].simulation_state->lock);
	pthread_mutex_destroy(&philos[0].simulation_state->lock_stdout);
	i = 0;
	while (i != (size_t)philos[0].philo_const->nb_philo)
		pthread_mutex_destroy(&philos[i++].left_fork.lock);
}

static void	create_threads(t_philo *philos)
{
	pthread_t	pthread;
	size_t		i;

	i = 0;
	while (i < (size_t)philos[0].philo_const->nb_philo)
	{
		philos[i].fake_thread_id = i + 1;
		pthread_create(&pthread, NULL, &main_routine, &philos[i]);
		philos[i].thread_id = pthread;
		usleep(500);
		i++;
	}
	i = 0;
	while (i < (size_t)philos[0].philo_const->nb_philo)
		pthread_join(philos[i++].thread_id, NULL);
	destroy_mutex(philos);
}

int	main(int argc, char *argv[])
{
	t_philo			*philos;
	t_simulation	simulation_state;
	t_philo_const	philo_const;

	if (argc != 6 && argc != 5)
	{
		printf("%s", MSG_FMT);
		return (1);
	}
	if (set_philo_const(argv, &philo_const))
		return (1);
	if (philo_const.nb_philo == 0
		|| (argv[5] && philo_const.nb_times_philosopher_must_eat == 0))
		return (0);
	philos = set_philos(&simulation_state, &philo_const);
	if (!philos)
		return (1);
	create_threads(philos);
	free(philos);
	return (0);
}
