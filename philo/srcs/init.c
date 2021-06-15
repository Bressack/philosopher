/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:14:29 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/16 01:14:57 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	get_arg(int *errorno, int *dest, char *src)
{
	long	tmp;

	if (isnumber(src) == FAILURE)
	{
		*errorno = 1;
		error(INVALID_NUMBER);
		return ;
	}
	tmp = ft_atol(src);
	if (tmp < 0 || tmp > INT_MAX)
	{
		*errorno = 1;
		error(NUMBER_OUT_OF_RANGE);
		return ;
	}
	*dest = (int)tmp;
}

int	init_mutexes(t_info *info)
{
	int	i;

	info->forks = malloc(info->philo_count * sizeof(pthread_mutex_t));
	if (info->forks == NULL)
		return (error(MALLOC_ERROR));
	i = 0;
	while (i < info->philo_count)
	{
		if (pthread_mutex_init(&info->forks[i], NULL) != 0)
			return (error(MUTEX_INIT));
		i++;
	}
	if (pthread_mutex_init(&info->talk, NULL) != 0)
		return (error(MUTEX_INIT));
	if (pthread_mutex_init(&info->iseatting, NULL) != 0)
		return (error(MUTEX_INIT));
	return (SUCCESS);
}

int	init_philos(t_info *info)
{
	int	i;

	info->philo = malloc(info->philo_count * sizeof(t_philo));
	if (info->philo == NULL)
		return (error(MALLOC_ERROR));
	i = 0;
	while (i < info->philo_count)
	{
		info->philo[i].id = i + 1;
		info->philo[i].meal_count = 0;
		info->philo[i].right_fork = i;
		info->philo[i].left_fork = (i + 1) % info->philo_count;
		info->philo[i].info = info;
		info->philo[i].last_meal = 0;
		i++;
	}
	return (SUCCESS);
}

int	init(t_info *info, int ac, char **av)
{
	int	errorno;

	errorno = 0;
	info->color_opt = 0;
	if (ac < 5 || ac > 7)
		return (error(INVALID_ARG_COUNT));
	get_arg(&errorno, &info->philo_count, av[1]);
	get_arg(&errorno, &info->time_die, av[2]);
	get_arg(&errorno, &info->time_eat, av[3]);
	get_arg(&errorno, &info->time_sleep, av[4]);
	info->meal_limit = -1;
	if (ac >= 6)
		get_arg(&errorno, &info->meal_limit, av[5]);
	if (errorno)
		return (FAILURE);
	if (info->philo_count < 2)
		return (error(NOT_ENOUGH_PHILO));
	info->stop_simulation = 0;
	if (init_mutexes(info) == FAILURE)
		return (FAILURE);
	if (init_philos(info) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
