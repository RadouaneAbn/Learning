
#!/bin/bash

echo "What's your name?"
read name
readonly name        # after this "name" wont change (readonly)
echo "Hello $name"
name="sara"          #the name wont change because name is read only variable
