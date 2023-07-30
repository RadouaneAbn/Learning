
#!/bin/bash

a=0
while [ "$a" -lt 10 ]     #this is loop 1
do
    b="$a"
    while [ "$b" -ge 0 ]  #this is loop 2
    do
	echo -n "$b "     # -n >> new line
	b=$(expr $b - 1)  #or b=$((b - 1))
    done
    echo
    a=$(expr $a + 1)
done
