# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    testsf.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/16 02:46:51 by tharchen          #+#    #+#              #
#    Updated: 2021/06/16 02:51:55 by tharchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/env zsh

STOP=0
while (( $STOP == 0 )); do
	./philo 4 410 2 4 4
	STOP=$?
	echo "STOP: " $STOP
	if (( $STOP == 0 )); then
		echo "STOP == 0"
	else
		echo "STOP != 0"
	fi
done