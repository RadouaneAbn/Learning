#!/bin/bash
up="before"
since="i used a local function here!! ;D"
echo $up
echo $since
showuptime(){                       # the function always comes first
    up=$(uptime -p | cut -c4-)      # cut -c4- will start printing from the 4 charachter (in this char start with 1 not 0)
    local since=$(uptime -s)
    cat <<EOF                       # this allow you to print (cat) from the first EOF to last EOF
--------
This machin has been up for ${up}
It has been running since ${since}
--------
EOF
}
showuptime                          # after defining the function, its time to call it
echo $up
echo $since
