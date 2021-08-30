/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 07:44:07 by zakdim            #+#    #+#             */
/*   Updated: 2021/07/17 06:37:49 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophr.h"

int	clear_state(t_state *state)
{
	int	i;

	if (state)
		free(state);
	if (state->forks_m)
	{
		i = 0;
		while (i < state->nbr_philo)
			pthread_mutex_destroy(&state->forks_m[i++]);
		free(state->forks_m);
	}
	if (state->philos)
	{
		i = 0;
		while (i < state->nbr_philo)
		{
			pthread_mutex_destroy(&state->philos[i].mutex);
			pthread_mutex_destroy(&state->philos[i++].eat_m);
		}
		free(state->philos);
	}
	pthread_mutex_destroy(&state->write_m);
	pthread_mutex_destroy(&state->somebody_dead_m);
	return (1);
}

int	exit_error(char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	return (1);
}
