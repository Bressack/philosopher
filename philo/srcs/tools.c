/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 12:14:55 by tharchen          #+#    #+#             */
/*   Updated: 2021/06/16 01:29:51 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int		isnumber(char *s)
{
	int		i;
	int		j;

	i = 0;
	while ((s[i] == '\t') || (s[i] == '\n') || (s[i] == '\r') ||
		(s[i] == '\v') || (s[i] == '\f') || (s[i] == ' '))
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	j = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (FAILURE);
		j++;
		i++;
	}
	if (!j || j > 10)
		return (FAILURE);
	return (SUCCESS);
}

long	ft_atol(const char *str)
{
	int i;
	long nbr;
	int neg;

	nbr = 0;
	neg = 0;
	i = 0;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\r') ||
			(str[i] == '\v') || (str[i] == '\f') || (str[i] == ' '))
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr *= 10;
		nbr += (int)str[i] - '0';
		i++;
	}
	if (neg == 1)
		return (-nbr);
	else
		return (nbr);
}

long	gettime(void)
{
	struct timeval  tp;

	gettimeofday(&tp, NULL);
	return ((tp.tv_sec * 1000) + (tp.tv_usec / 1000));
}

void	print_state(t_info *info, int id, char *msg, char *color)
{
	pthread_mutex_lock(&info->talk);
	if (info->stop_simulation)
	{
		pthread_mutex_unlock(&info->talk);
		return ;
	}
	if (!info->color_opt)
		color = "";
	printf("%ld %d %s%s"C_RES"\n", gettime() - info->start_timestamp, id, color,
		msg);
	pthread_mutex_unlock(&info->talk);
}

void		ft_usleep(t_info *info, long t)
{
	long start;

	start = gettime();
	while (!(info->stop_simulation))
	{
		if (gettime() - start >= t)
			break ;
		usleep(50);
	}
}
