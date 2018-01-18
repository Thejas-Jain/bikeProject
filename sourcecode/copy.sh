#!/bin/bash
###############################################
cd server
make clean
make

mkdir -p $HOME/PRO2016
mkdir -p $HOME/PRO2016/bin
mkdir -p $HOME/PRO2016/log
mkdir -p $HOME/PRO2016/resource
mkdir -p $HOME/PRO2016/Conf

scp bin/server $HOME/PRO2016/bin
scp resources/database.txt $HOME/PRO2016/resource/
touch $HOME/PRO2016/log/syslog.txt
scp config $HOME/PRO2016/Conf/Config.conf

