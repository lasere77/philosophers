/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:37:36 by mcolin            #+#    #+#             */
/*   Updated: 2026/01/09 15:00:25 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MSG_FMT "please use the format:\n./philo number_of_philosophers \
time_to_die time_to_eat time_to_sleep \
optional: [number_of_times_each_philosopher_must_eat]\n"

#include "philo.h"

#include <stdio.h>
// flag valgrind: --toollgrind

int	main(int argc, char *argv[])
{
	t_philo	*philos;

	if (argc != 6 && argc != 5)
	{
		printf("%s", MSG_FMT);
		return (1);
	}
	philos = set_philos(argv);
	if (!philos)
		return (1);
	free_philos(philos);
	return (0);
}
