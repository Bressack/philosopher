/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eatting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 01:20:20 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/16 01:20:22 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	eatting(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	pthread_mutex_lock(&(info->forks[philo->left_fork]));
	print_state(info, philo->id, MSG_FORK, MSG_FORK_COLOR);
	pthread_mutex_lock(&(info->forks[philo->right_fork]));
	print_state(info, philo->id, MSG_FORK, MSG_FORK_COLOR);
	pthread_mutex_lock(&info->iseatting);
	print_state(info, philo->id, MSG_EAT, MSG_EAT_COLOR);
	philo->last_meal = gettime();
	pthread_mutex_unlock(&info->iseatting);
	ft_usleep(info, info->time_eat);
	philo->meal_count++;
	pthread_mutex_unlock(&(info->forks[philo->left_fork]));
	pthread_mutex_unlock(&(info->forks[philo->right_fork]));
}
