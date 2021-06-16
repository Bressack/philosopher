/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:14:59 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/16 02:12:54 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*philo_thread(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;
	// usleep(1500);
	if (philo->id % 2)
		usleep(1500);
	while (!info->stop_simulation)
	{
		eatting(philo);
		if (info->stop_simulation)
			break ;
		print_state(info, philo->id, MSG_SLEEP, MSG_SLEEP_COLOR);
		ft_usleep(info, info->time_sleep);
		print_state(info, philo->id, MSG_THINK, MSG_THINK_COLOR);
	}
	return (0);
}

void	death_checker_each(t_info *info, int i)
{
	t_philo	*philo;

	philo = info->philo;
	pthread_mutex_lock(&info->iseatting);
	if (gettime() - philo[i].last_meal > info->time_die)
	{
		pthread_mutex_lock(&info->talk);
		printf("%ld %d %s%s"C_RES"\n",
			gettime() - info->start_timestamp,
			philo[i].id, MSG_DEATH_COLOR, MSG_DEATH);
		info->stop_simulation = 1;
		pthread_mutex_unlock(&info->talk);
	}
	pthread_mutex_unlock(&info->iseatting);
	usleep(50);
}

void	death_checker(t_info *info)
{
	t_philo	*philo;
	int		i;

	philo = info->philo;
	while (!info->stop_simulation)
	{
		i = 0;
		while (i < info->philo_count)
		{
			death_checker_each(info, i);
			i++;
			if (info->stop_simulation)
				break ;
		}
		i = 0;
		while (info->meal_limit != -1 && i < info->philo_count
			&& philo[i].meal_count >= info->meal_limit)
			i++;
		if (i == info->philo_count)
			info->stop_simulation = 1;
	}
}

void	clean_and_exit(t_info *info)
{
	t_philo	*philo;
	int		i;

	philo = info->philo;
	i = 0;
	while (i < info->philo_count)
	{
		pthread_detach(philo[i].tid);
		i++;
	}
	i = 0;
	while (++i < info->philo_count)
	{
		pthread_mutex_destroy(&(info->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(info->talk));
	pthread_mutex_destroy(&(info->iseatting));
}

int	simulation(t_info *info)
{
	int	i;

	info->start_timestamp = gettime();
	i = 0;
	while (i < info->philo_count)
	{
		if (pthread_create(
				&info->philo[i].tid, NULL, philo_thread,
				&(info->philo[i])) != 0)
			return (error(THREAD_CREATE));
		info->philo[i].last_meal = gettime();
		i++;
	}
	death_checker(info);
	clean_and_exit(info);
	return (SUCCESS);
}
