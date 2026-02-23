/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:00:29 by mcolin            #+#    #+#             */
/*   Updated: 2026/02/23 15:28:10 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_routines.h"
#include "routines_utils.h"
#include "philo.h"
#include "utils.h"

static bool	take_fork(t_philo *philo, t_fork *fork)
{
	while (get_simulation_state(philo))
	{
		if ((get_time_stamps(philo->simulation_state->start)
				- philo->time_before_dying) >= philo->philo_const->time_to_die)
			return (1);
		pthread_mutex_lock(&fork->lock);
		if (fork->available == true)
		{
			pthread_mutex_lock(&philo->simulation_state->lock_stdout);
			printf("%s %lu %lu has taken a fork\n", COLOR_LIGHT_CYAN,
				get_time_stamps(philo->simulation_state->start),
				philo->fake_thread_id);
			pthread_mutex_unlock(&philo->simulation_state->lock_stdout);
			fork->available = false;
			pthread_mutex_unlock(&fork->lock);
			break ;
		}
		pthread_mutex_unlock(&fork->lock);
		usleep(500);
	}
	return (0);
}

static bool	eat_routine(t_philo	*philo)
{
	if (take_fork(philo, &philo->left_fork)
		|| take_fork(philo, philo->right_fork))
		return (1);
	philo->time_before_dying = get_time_stamps(philo->simulation_state->start);
	if (!get_simulation_state(philo))
		return (1);
	pthread_mutex_lock(&philo->simulation_state->lock_stdout);
	printf("%s %lu %lu is eating\n", COLOR_PURPLE,
		get_time_stamps(philo->simulation_state->start), philo->fake_thread_id);
	pthread_mutex_unlock(&philo->simulation_state->lock_stdout);
	philo->nb_eat++;
	update_simulation(philo);
	sleep_val(philo, philo->philo_const->time_to_eat);
	pthread_mutex_lock(&philo->left_fork.lock);
	philo->left_fork.available = true;
	pthread_mutex_unlock(&philo->left_fork.lock);
	pthread_mutex_lock(&philo->right_fork->lock);
	philo->right_fork->available = true;
	pthread_mutex_unlock(&philo->right_fork->lock);
	return (0);
}

static bool	sleep_routine(t_philo *philo)
{
	if (!get_simulation_state(philo))
		return (1);
	pthread_mutex_lock(&philo->simulation_state->lock_stdout);
	printf("%s %lu %lu is sleeping\n", COLOR_BROWN,
		get_time_stamps(philo->simulation_state->start), philo->fake_thread_id);
	pthread_mutex_unlock(&philo->simulation_state->lock_stdout);
	return (fall_asleep(philo, philo->philo_const->time_to_sleep
			* MILLISECOND_IN_MICROSECOND));
}

static inline void	thinking_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->simulation_state->lock_stdout);
	printf("%s %lu %lu is thinking\n", COLOR_LIGHT_GREEN,
		get_time_stamps(philo->simulation_state->start), philo->fake_thread_id);
	pthread_mutex_unlock(&philo->simulation_state->lock_stdout);
}

void	*main_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->time_before_dying = get_time_stamps(philo->simulation_state->start);
	while (get_simulation_state(philo)
		&& philo->simulation_state->nb_philo_must_eat
		!= philo->philo_const->nb_philo)
	{
		if (eat_routine(philo))
			break ;
		if (sleep_routine(philo))
			break ;
		if (get_simulation_state(philo)
			&& philo->simulation_state->nb_philo_must_eat
			!= philo->philo_const->nb_philo)
			thinking_routine(philo);
	}
	if (get_simulation_state(philo))
		end_simulation(philo);
	return (NULL);
}
