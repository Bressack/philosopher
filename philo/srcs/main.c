/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:15:04 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/16 02:36:19 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int ac, char **av)
{
	t_info	info;

	if (ac < 5 || ac > 6)
		printf("usage: %s %s%s\n", av[0], USAGE, USAGE2);
	if (init(&info, ac, av) == FAILURE)
		return (FAILURE);
	if (simulation(&info) == FAILURE)
		return (FAILURE);
	return (0);
}
