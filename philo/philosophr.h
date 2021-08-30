/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophr.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 09:07:02 by zakdim            #+#    #+#             */
/*   Updated: 2021/07/16 17:37:16 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHR_H
# define PHILOSOPHR_H
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# define TYPE_SLEEP 1
# define TYPE_FORK 	2
# define TYPE_EAT 0
# define TYPE_THINK	3
# define TYPE_DIED 	4
# define TYPE_OVER 	5

typedef struct s_philo
{
	int				position;
	int				is_eating;
	int				lfork;
	int				rfork;
	uint64_t		limit;
	uint64_t		last_eat;
	int				eat_count;
	struct s_state	*state;
	pthread_mutex_t	mutex;
	pthread_mutex_t	eat_m;
}					t_philo;

typedef struct s_state
{
	int				nbr_philo;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	int				must_eat_count;
	uint64_t		start;
	int				total;
	t_philo			*philos;
	pthread_mutex_t	*forks_m;
	pthread_mutex_t	write_m;
	pthread_mutex_t	somebody_dead_m;
}					t_state;

int					ft_strlen(char const *str);
int					ft_atoi(char const *str);
void				ft_putnbr_fd(uint64_t n, int fd);
uint64_t			get_time(void);
int					clear_state(t_state *state);
int					exit_error(char const *str);
int					init(t_state *state, int argc, char **argv);
void				take_forks(t_philo *philo);
void				clean_forks(t_philo *philo);
void				eat(t_philo *philo);
void				display_message(t_philo *philo, int type);
int					check_digit(char **s);

#endif