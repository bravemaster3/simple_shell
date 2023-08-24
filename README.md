# simple_shell
This is a custom shell that emulates sh (not bash)
Compilation command
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
Run the shell
./hsh <command> arguments
```
#example:
/bin/ls
exit 98
```
## Builtin commands

* exit: Usage --> "exit" OR "exit status". When more than one additinal arguments are found, the others are ignored.
* env: working, but prints in different order than the real sh env builtin

## Own personalized functions
* getline: fully functional




## NOTES

* if the argument is only spaces? Token is NULL. Not handled before!! NOW HANDLED, and TASK 1 ALL CHECKED OK
* Task 2, ALL CHECKED OK
* We were printing to the stdout even errors... This was causing a lot more errors when using the checker. I have now made _putchar2 and _puts2 which take in also a file descriptor. Now, Task 3 is almost all green! Yey!! Only one left to solve.
* task 5 passes 1 check out of 3
* tasks 1, 2, 3, 4, 6 and 8 seems good. Betty also, so, task 0 too. Task 5 might be good. we'll see when the checker is released


* Ready for first deadline. Yes!

