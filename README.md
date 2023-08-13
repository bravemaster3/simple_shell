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
# Builtin commands

* exit: Usage --> "exit" OR "exit status". When more than one additinal arguments are found, the others are ignored.
* env:

