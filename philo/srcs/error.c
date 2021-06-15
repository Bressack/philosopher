/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:14:48 by tharchen          #+#    #+#             */
/*   Updated: 2021/05/22 14:35:33 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int		error(char *msg)
{
	write(2, ERROR_FRONT, strlen(ERROR_FRONT));
	write(2, msg, strlen(msg));
	write(2, "\n", 1);
	return (FAILURE);
}
