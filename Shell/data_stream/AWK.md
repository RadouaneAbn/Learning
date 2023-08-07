awk 'command' file
awk '{print}' tmnt.txt == awk '{print $0}' tmnt.txt
	this command will print the content of tmnt.txt (same as cat).

awk '{print $1} file
this command will print the first field of avary line.
Ex:	
	⮞ awk '{print $1}' tmnt.txt
	leonardo
	raphael
	michelangelo
	donatello

awk '{print $NF}' file
this command will print the last field of every line in 'file'.
Ex:
	⮞ awk '{print $NF}' tmnt.txt
	leader
	hothead
	party-animal
	geek

⮞ awk -F':' '{print $1,$7}' /etc/passwd | tail
this command will print the 1 and 7 fields of the  last 10 lines

	*systemd-resolve /usr/sbin/nologin*
	*messagebus /usr/sbin/nologin*
	*systemd-timesync /usr/sbin/nologin*
	*syslog /usr/sbin/nologin*
	*_apt /usr/sbin/nologin*
	*uuidd /usr/sbin/nologin*
	*tcpdump /usr/sbin/nologin*
	*radouane /bin/zsh*
	*red /bin/bash*
	*sshd /usr/sbin/nologin*
