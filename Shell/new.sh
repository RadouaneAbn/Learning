
#!/bin/bash

createXfile() {
    name=${1:-default_file.txt}
    exe=$(echo "$name" | awk -F'.' '{print $NF}')
    if [ $exe = "sh" ]; then
    touch "$name"
    chmod 744 "$name"
    emacs "$name"
    else
	echo "This is not SH file"
    fi
    
    
}

# Call the createXfile function with the provided filename as an argument,
# or use the default filename "default_file.txt" if no argument is provided
createXfile "$1"
