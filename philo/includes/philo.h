/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:07:58 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/16 02:36:45 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <sys/types.h>
# include <stdarg.h>
# include <strings.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/time.h>
# include <color_shell.h>
# define INT_MAX		2147483647
# define ERROR_FRONT	"error: "
# define USAGE		"number_of_philosopher time_to_die time_to_eat time_to_slee"
# define USAGE2		"p number_of_time_each_philosophers_must_eat"

# define MSG_FORK			"has taken a fork"
# define MSG_FORK_COLOR		C_G_YELLOW
# define MSG_EAT			"is eating"
# define MSG_EAT_COLOR		C_G_GREEN
# define MSG_SLEEP			"is sleeping"
# define MSG_SLEEP_COLOR	C_G_CYAN
# define MSG_THINK			"is thinking"
# define MSG_THINK_COLOR	C_G_GRAY
# define MSG_DEATH			"died"
# define MSG_DEATH_COLOR	C_G_RED
# define THREAD_CREATE			"unable to create thread"
# define MUTEX_INIT				"unable to init mutex"
# define MALLOC_ERROR			"unable to allocate more memory"
# define NOT_ENOUGH_PHILO	"not enough philosophers to start the simulation"
# define INVALID_ARG_COUNT		"invalid argument count"
# define INVALID_NUMBER			"argument not a number"
# define NUMBER_OUT_OF_RANGE	"argument value out of range"

typedef enum e_error_ret
{
	FAILURE = -1,
	SUCCESS	= 0
}				t_error_ret;

struct	s_philo;

typedef struct s_info
{
	int				color_opt;
	int				philo_count;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				meal_limit;
	pthread_mutex_t	*forks;
	pthread_mutex_t	talk;
	pthread_mutex_t	iseatting;
	int				stop_simulation;
	long			start_timestamp;
	struct s_philo	*philo;
}					t_info;
typedef struct s_philo
{
	int				id;
	pthread_t		tid;
	int				meal_count;
	int				right_fork;
	int				left_fork;
	long			last_meal;
	int				isdead;
	struct s_info	*info;
}					t_philo;
/*
** INIT
*/
int		init(t_info *info, int ac, char **av);

/*
** ERROR
*/
int		error(char *msg);

/*
** SIMULATION
*/
void	eatting(t_philo *philo);
int		simulation(t_info *info);
/*
** TOOLS
*/
int		isnumber(char *s);
long	ft_atol(const char *str);
long	gettime(void);
void	print_state(t_info *info, int id, char *msg, char *color);
void	ft_usleep(t_info *info, long t);
/*
** UTILS
*/
int		ft_strlen(char *s);
#endif
