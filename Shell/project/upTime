#!/bin/bash

showuptime(){
    up=$(uptime -p | cut -c4-) 
    since=$(uptime -s)
    cat <<EOF
--------
This machin has been up fpr ${up}
It has been running since ${since}
--------
EOF
}
showuptime
