/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:38:18 by mcolin            #+#    #+#             */
/*   Updated: 2026/02/24 10:45:46 by mcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINES_UTILS_H
# define ROUTINES_UTILS_H

# include "philo.h"

# include <stdio.h>
# include <unistd.h>

# define COLOR_RED "\e[0;31m"
# define COLOR_LIGHT_GREEN "\e[1;32m"
# define COLOR_BROWN "\e[0;33m"
# define COLOR_PURPLE "\e[0;35m"
# define COLOR_LIGHT_CYAN "\e[1;36m"

# define MILLISECOND_IN_MICROSECOND 1000

bool	get_simulation_state(t_philo *philo);
void	update_simulation(t_philo *philo);
void	sleep_val(t_philo *philo, size_t duration);
void	end_simulation(t_philo *philo);

#endif