LOG_DIR=~/tmp/sip_log
DATE=`date "+%F_%H:%M"`

/usr/sbin/tcpdump -v -nn -s0 -i eth1 net 195.39.211.0/24 and udp port 5060 | tee $LOG_DIR/sip-${DATE}.log
