/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:15:04 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/16 01:15:09 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int ac, char **av)
{
	t_info	info;

	if (init(&info, ac, av) == FAILURE)
		return (FAILURE);
	if (simulation(&info) == FAILURE)
		return (FAILURE);
	return (0);
}