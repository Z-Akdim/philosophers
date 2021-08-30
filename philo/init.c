/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 07:43:12 by zakdim            #+#    #+#             */
/*   Updated: 2021/07/16 16:53:51 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophr.h"

static int	init_mutexes(t_state *state)
{
	int	i;

	pthread_mutex_init(&state->write_m, NULL);
	pthread_mutex_init(&state->somebody_dead_m, NULL);
	pthread_mutex_lock(&state->somebody_dead_m);
	state->forks_m = (pthread_mutex_t *)malloc
		(sizeof(*(state->forks_m)) * state->nbr_philo);
	if (!(state->forks_m))
		return (1);
	i = 0;
	while (i < state->nbr_philo)
		pthread_mutex_init(&state->forks_m[i++], NULL);
	return (0);
}

static void	init_philos(t_state *state)
{
	int	i;

	i = 0;
	while (i < state->nbr_philo)
	{
		state->philos[i].is_eating = 0;
		state->philos[i].position = i;
		state->philos[i].lfork = i;
		state->philos[i].rfork = (i + 1) % state->nbr_philo;
		state->philos[i].state = state;
		state->philos[i].eat_count = 0;
		pthread_mutex_init(&state->philos[i].mutex, NULL);
		pthread_mutex_init(&state->philos[i].eat_m, NULL);
		pthread_mutex_lock(&state->philos[i].eat_m);
		i++;
	}
}

int	init(t_state *state, int argc, char **argv)
{
	state->nbr_philo = ft_atoi(argv[1]);
	state->time_to_die = ft_atoi(argv[2]);
	state->time_to_eat = ft_atoi(argv[3]);
	state->time_to_sleep = ft_atoi(argv[4]);
	state->forks_m = NULL;
	state->philos = NULL;
	if (argc == 6)
		state->must_eat_count = ft_atoi(argv[5]);
	else
		state->must_eat_count = -1;
	if ((state->nbr_philo < 1 || state->nbr_philo > 200)
		|| state->time_to_die < 60
		|| state->time_to_eat < 60 || state->time_to_sleep < 60)
	{
		exit_error("Error: bad arguments\n");
		exit (0);
	}
	state->philos = (t_philo *)
		malloc(sizeof(*(state->philos)) * state->nbr_philo);
	if (!(state->philos))
		return (1);
	init_philos(state);
	return (init_mutexes(state));
}
