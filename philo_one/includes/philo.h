/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:07:58 by tharchen          #+#    #+#             */
/*   Updated: 2021/05/23 14:33:07 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <libc.h>
# include <pthread.h>
# include <sys/time.h>
# include <color_shell.h>

# define ERROR_FRONT	C_G_RED"error: "C_RES
# define USAGE		"number_of_philosopher time_to_die time_to_eat time_to_slee\
p number_of_time_each_philosophers_must_eat"

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
# define NOT_ENOUGH_PHILO		"not enough philosophers to start the simulation"
# define INVALID_ARG_COUNT		"invalid argument count"
# define INVALID_NUMBER			"argument not a number"
# define NUMBER_OUT_OF_RANGE	"argument value out of range"

typedef enum		e_error_ret
{
	FAILURE = -1,
	SUCCESS	= 0
}					t_error_ret;

struct s_philo;

typedef struct		s_info
{
	int				color_opt;			// color option
	int				philo_count;		// number of philosopher
	int				time_die;			// time to die in ms
	int				time_eat;			// time to eat in ms
	int				time_sleep;			// time to sleep in ms
	int				meal_limit;			// number of meal to stop the simulation
	pthread_mutex_t	*forks;				// forks in alloced array
	pthread_mutex_t	talk;				// to avoid overlap in term when philos talk
	pthread_mutex_t	iseatting;			// to be sure a philo can write "is eating" and get new time for new meal without dying
	int				stop_simulation;	// if  a philo is dead or all philo have eat `meal_limit` times, the simulation stops
	long			start_timestamp;	// timestamp start simulation
	struct s_philo	*philo;				// philosophers struct array
}					t_info;
typedef struct		s_philo
{
	int				id;					// id of the philo [1-philo_count]
	pthread_t		tid;				// thread id of the philo thread
	int				meal_count;			// number of meal the philo have done
	int				right_fork;			// index of his right fork
	int				left_fork;			// index of his left fork
	long			last_meal;			// timestamp last meal
	int				isdead;
	struct s_info	*info;				// info struct
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
int		simulation(t_info *info);
/*
** TOOLS
*/
int		isnumber(char *s);
long	ft_atol(const char *str);
long	gettime(void);
void	print_state(t_info *info, int id, char *msg, char *color);
void	ft_usleep(t_info *info, long t);
#endif
