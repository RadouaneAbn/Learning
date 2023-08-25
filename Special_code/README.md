**Special code**  
print_number:  
	if  (m / 10)
		print_number(m / 10);
	_putchar(m % 10 + '0');

these three lines of code works like a loop.
example (print the number 123):
* STEP I : first the function checks if m(123) / 10 is true (!0)
* true > the function sends m(123) / 10 = 12 to function again
  in this case m becomes m / 10 wich is 123 / 10 = 12
* STEP II : the function this time check if m(12) / 10 is true (!)
* true > the function send m(12) / 10 = 1 to the function again :)
  now m becomes m(12) / 10 = 1
* STEP III : the function again checks if m(1) / 10 is true (!0)
* false > the function printf the "m % 10" char 
1- in this step m % 10 = 1 then goes back to the previous step (II)
2- now prints (m(12) % 10) = 2 then goes back to the previous step (I)
3- now prints (m(123) % 10) = 3 and exits the function.

