date=`date "+%F_%H:%M"`
/usr/sbin/tcpdump -v -nn -s0 -i eth1 host 195.39.211.241 and udp port 5060 | tee sip-${date}.log
