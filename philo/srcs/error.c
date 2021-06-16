/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:14:48 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/16 02:34:41 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	print_things(int fd, int nb_things, ...)
{
	va_list	ap;
	char	*str;

	va_start(ap, nb_things);
	while (nb_things)
	{
		str = va_arg(ap, char *);
		if (str)
			write(fd, str, ft_strlen(str));
		nb_things--;
	}
	va_end(ap);
}

int	error(char *msg)
{
	write(2, C_G_RED, ft_strlen(C_G_RED));
	write(2, ERROR_FRONT, ft_strlen(ERROR_FRONT));
	write(2, C_RES, ft_strlen(C_RES));
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return (FAILURE);
}
