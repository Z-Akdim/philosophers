/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 07:43:42 by zakdim            #+#    #+#             */
/*   Updated: 2021/07/16 11:49:53 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophr.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->state->forks_m[philo->lfork]);
	if (philo->eat_count != philo->state->must_eat_count)
		display_message(philo, TYPE_FORK);
	pthread_mutex_lock(&philo->state->forks_m[philo->rfork]);
	if (philo->eat_count != philo->state->must_eat_count)
		display_message(philo, TYPE_FORK);
}

void	clean_forks(t_philo *philo)
{
	if (philo->eat_count != philo->state->must_eat_count)
		display_message(philo, TYPE_SLEEP);
	pthread_mutex_unlock(&philo->state->forks_m[philo->lfork]);
	pthread_mutex_unlock(&philo->state->forks_m[philo->rfork]);
	usleep(philo->state->time_to_sleep * 1000);
}
