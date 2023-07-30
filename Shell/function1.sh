
#!/bin/sh
#Define function

Hello(){
    echo "Hello $1 $2 "
    return 10
}

#Invoke Function
Hello Radouane abounouas

#Capture value returned previously
ret=$?
echo "Return value is $ret"
