
#!/bin/bash

# Convert the first argument (username) to lowercase
username=$(echo "$1" | tr '[:upper:]' '[:lower:]')

case "$username" in
    radouane | administrator)
        echo "Hello, you're the boss here!"
        ;;
    help)
        echo "Just enter your username!"
        ;;
    *)
        echo "Hello there. You're not the boss of me. Enter a valid username!"
esac
