
#!/bin/bash

is_alive_ping(){
    ping -c 1 $1 > /dev/null
    if [ $? -eq 0 ]; then
    echo "Node with IP : $i is up"
    fi
}

i=1
while [ $i -le 255 ]
do
    ip="192.168.1.$i"
    is_alive_ping "$ip" &
    i=$((i + 1))
done
exit
