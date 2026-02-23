/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:00:00 by mcolin            #+#    #+#             */
/*   Updated: 2026/02/23 14:52:58 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <pthread.h>
# include <stddef.h>
# include <sys/time.h>

typedef struct s_philo_const
{
	size_t	time_to_die;
	size_t	time_to_sleep;
	int		time_to_eat;
	int		nb_times_philosopher_must_eat;
	int		nb_philo;
}			t_philo_const;

typedef struct s_fork
{
	pthread_mutex_t	lock;
	bool			available;
}					t_fork;

typedef struct s_simulation
{
	pthread_mutex_t	lock;
	pthread_mutex_t	lock_stdout;
	struct timeval	start;
	bool			state_simulation;
	int				nb_philo_must_eat;
}					t_simulation;

typedef struct s_philo
{
	t_fork			left_fork;
	t_fork			*right_fork;
	t_philo_const	*philo_const;
	t_simulation	*simulation_state;
	long			time_before_dying;
	pthread_t		thread_id;
	size_t			fake_thread_id;
	int				nb_eat;
}					t_philo;

t_philo	*set_philos(t_simulation *simulation_state, t_philo_const *philo_const);
bool	set_philo_const(char *argv[], t_philo_const *philo_const);

#endif