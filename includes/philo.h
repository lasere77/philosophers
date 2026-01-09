/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:00:00 by mcolin            #+#    #+#             */
/*   Updated: 2026/01/09 14:58:47 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <pthread.h>

typedef struct s_philo_const
{
	size_t	nb_philo;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	nb_times_philosopher_must_eat;
}			t_philo_const;

typedef struct s_fork
{
	pthread_mutex_t	lock;
	bool			available;
}					t_fork;

typedef struct s_philo
{
	t_fork			left_fork;
	t_fork			*right_fork;
	t_philo_const	*philo_const;
	bool			*active_simulation;
	size_t			thead_id;
	size_t			nb_eat;
}					t_philo;

t_philo			*set_philos(char **argv);
void			free_philos(t_philo *philos);
t_philo_const	*set_philo_const(char *argv[]);

#endif