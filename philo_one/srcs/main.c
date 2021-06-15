/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:15:04 by tharchen          #+#    #+#             */
/*   Updated: 2021/05/23 12:43:58 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	debug(t_info info)
{
	printf("info.philo_count      : %d\n", info.philo_count);
	printf("info.time_die         : %d\n", info.time_die);
	printf("info.time_eat         : %d\n", info.time_eat);
	printf("info.time_sleep       : %d\n", info.time_sleep);
	printf("info.meal_limit       : %d\n", info.meal_limit);
	printf("info.forks            : %p\n", info.forks);
	printf("info.stop_simulation  : %d\n", info.stop_simulation);
	printf("info.philo            : %p\n", info.philo);
	printf("\n");
	for (int i = 0; i < info.philo_count; i++)
	{
		printf("philosophers %d:\n", info.philo[i].id);
		printf("info->philo[%d]->id         : %d\n", i, info.philo[i].id);
		printf("info->philo[%d]->meal_count : %d\n", i, info.philo[i].meal_count);
		printf("info->philo[%d]->right_fork : %d\n", i, info.philo[i].right_fork);
		printf("info->philo[%d]->left_fork  : %d\n", i, info.philo[i].left_fork);
		printf("\n");
	}
}

int		main(int ac, char **av)
{
	t_info	info;

	if (init(&info, ac, av) == FAILURE)
		return (FAILURE);
	// debug(info);
	if (simulation(&info) == FAILURE)
		return (FAILURE);
	return (0);
}
