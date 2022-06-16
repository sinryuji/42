#!/bin/bash
arc=$(uname -a)
pcpu=$(cat /proc/cpuinfo | grep "physical id" | sort | uniq | wc -l)
vcpu=$(cat /proc/cpuinfo | grep "processor" | wc -l)
tram=$(free -m | awk '$1 == "Mem:" {print $2}')
uram=$(free -m | awk '$1 == "Mem:" {print $3}')
pram=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')
tdisk=$(df -Bg | grep '^/dev/' | grep -v '/boot' | awk '{td += $2} END {print td}')
udisk=$(df -Bm | grep '^/dev/' | grep -v '/boot' | awk '{ud += $3} END {print ud}')
pdisk=$(df -Bm | grep '^/dev/' | grep -v '/boot' | awk '{td += $2} {ud += $3} END {printf("%d"), ud/td*100}')
cpul=$(top -bn1 | grep '^%Cpu' | awk '{printf("%.1f%%"), $2 + $4}')
lb=$(who -b | awk '{print $3 " " $4}')
lvmt=$(lsblk | grep "lvm" | wc -l)
lvmu=$(if [ $lvmt -eq 0 ]; then echo no; else echo yes; fi)
ct=$(cat /proc/net/sockstat | grep '^TCP:' | awk '{print $3}')
ul=$(users | wc -w)
ip=$(hostname -I)
mac=$(ip link show | grep 'link/ether' | awk '{print $2}')
sudo=$(journalctl _COMM=sudo | grep 'COMMAND' | wc -l)
wall "	#Architecture: $arc
	#CPU phtsical: $pcpu
	#vCPU: $vcpu
	#Memory Usage: $uram/${tram}MB ($pram%)
	#Disk Usage: $udisk/${tdisk}Gb ($pdisk%)
	#CPU load: $cpul
	#Last boot: $lb
	#LVM use: $lvmu
	#Connections TCP: $ct ESTABLISHED
	#User log: $ul
	#Network: IP $ip ($mac)
	#Sudo: $sudo cmd"
