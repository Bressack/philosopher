# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    testsf.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/16 02:46:51 by tharchen          #+#    #+#              #
#    Updated: 2021/06/16 03:25:49 by tharchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/env zsh

TOTAL=0
SUCCESS=0
FAILURE=0
CRASH=0

for (( i = 2; i < 10; i++ )); do
	for (( j = 2; j < 11; j++ )); do
		for (( k = 1; k < 11; k++ )); do
			for (( l = 1; l < 11; l++ )); do
				m=-1
				# for (( m = -1; m < 2; m++ )); do
					printf " [ %3d / %-3d ][ %3d / %-3d ][ %3d / %-3d ][ %3d / %-3d ][ %3d / %-3d ] [ %d %d %d %d ]\r" $i 10 $j 11 $k 11 $l 11 $m 3 $TOTAL $SUCCESS $FAILURE $CRASH
					./philo $i $j $k $l > /dev/null 2> /dev/null &
					for (( z = 0; z < 300000; z++ )); do;done
					pkill philo
					RR=$?
					echo "RR:[" $RR "]"
					((TOTAL++))
					if (( $RR == 0 )); then
						((SUCCESS++))
					elif (( $RR == 255 )); then
						((FAILURE++))
					else
						((CRASH++))
					fi
				# done
			done
		done
	done
done

printf "total test: %5d | total success: %5d | total failure: %5d | total crash: %5d\n" $TOTAL $SUCCESS $FAILURE $CRASH
