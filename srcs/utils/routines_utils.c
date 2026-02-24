/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:37:57 by mcolin            #+#    #+#             */
/*   Updated: 2026/02/24 10:26:53 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routines_utils.h"
#include "utils.h"
#include <stddef.h>

bool	get_simulation_state(t_philo *philo)
{
	register bool	result;

	pthread_mutex_lock(&philo->simulation_state->lock);
	result = philo->simulation_state->state_simulation;
	pthread_mutex_unlock(&philo->simulation_state->lock);
	return (result);
}

void	sleep_val(t_philo *philo, size_t duration)
{
	long	start_smart_sleep;

	start_smart_sleep = get_time_stamps(philo->simulation_state->start);
	while (get_time_stamps(philo->simulation_state->start)
		- start_smart_sleep < duration && get_simulation_state(philo))
		usleep(50);
}

void	update_simulation(t_philo *philo)
{
	pthread_mutex_lock(&philo->simulation_state->lock);
	if (philo->nb_eat == philo->philo_const->nb_times_philosopher_must_eat)
		philo->simulation_state->nb_philo_must_eat++;
	pthread_mutex_unlock(&philo->simulation_state->lock);
}

void	end_simulation(t_philo *philo)
{
	pthread_mutex_lock(&philo->simulation_state->lock);
	philo->simulation_state->state_simulation = false;
	pthread_mutex_unlock(&philo->simulation_state->lock);
	pthread_mutex_lock(&philo->simulation_state->lock_stdout);
	pthread_mutex_lock(&philo->simulation_state->lock);
	if ((get_time_stamps(philo->simulation_state->start)
			- philo->time_before_dying) >= philo->philo_const->time_to_die)
	{
		printf("%s%lu %lu died\n", COLOR_RED,
			get_time_stamps(philo->simulation_state->start),
			philo->fake_thread_id);
	}
	pthread_mutex_unlock(&philo->simulation_state->lock);
	pthread_mutex_unlock(&philo->simulation_state->lock_stdout);
}
