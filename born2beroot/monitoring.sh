# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    monitoring.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lupelleg <lupelleg@student.42heilbronn.de  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/25 17:22:49 by lupelleg          #+#    #+#              #
#    Updated: 2025/03/27 11:55:28 by lupelleg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

INFO=$(cat <<EOF
#Architecture: $(uname -a)
#CPU physical: $(lscpu | grep 'Socket(s)' | awk '{print $2}')
#vCPU: $(nproc)
#Memory Usage: $(free -m | awk '/Mem:/ {printf "%d/%dMB (%.2f%%)", $3, $2, $3/$2*100}')
#Disk Usage: $(df -BG --total | grep 'total' | awk '{printf "%d/%dGb (%s)", $3, $2, $5}')
#CPU load: $(grep 'cpu ' /proc/stat | awk '{usage=($2+$4)*100/($2+$4+$5)} END {printf "%.1f", usage}')%
#Last boot: $(who -b | awk '{print $3, $4}')
#LVM use: $(lsblk | grep -q 'lvm' && echo "yes" || echo "no")
#Connections TCP: $(ss -t | grep ESTAB | wc -l) ESTABLISHED
#User log: $(who | wc -l)
#Network: IP $(hostname -I | awk '{print $1}') ($(ip link show | awk '/ether/ {print $2}'))
#Sudo: $(grep -c "COMMAND" /var/log/sudo/sudo.log) cmd
EOF
)
