# BombShell

This project is about recreating the shell in the C language, replicating some of processes of the `sh` shell. This version will be used as `./hsh`.
## Environment
Our version of the Shell has been tested on Ubuntu 14.05.5 LTS

Tests done in VirtualBox on [Ubuntu](https://atlas.hashicorp.com/ubuntu/boxes/trusty64) via [Vagrant](https://www.vagrantup.com/)(1.9.1)

## Repository Breakdown
Once cloned over, the repository will contain the following files:

|   **File**    |  **Decription**                       |
|---------------|---------------------------------------|
| shell.h   | header file with prototypes           |
| shell.c      | contains main function to the shell         |
| build_all_variables.c     | struct function that builds the variables             |
| builtin_funcs.c | functions for builtin commands |
| cmd_executor.c     | function that executes the commands from user input|
| envlist_to_array.c     | function that converts the environmental linked list to an double pointer array|
| env_funcs.c | functions to handle the environment |
| free_mem.c | functions that free memory allocation |
| get_builtin_func.c     | function that get the b|
| input_funcs.c | contains functions to handler user input |
| input_list_to_array.c | converts the input linked list to a double pointer |
| input_parserator.c     | function to parse the user's input |
| input_to_array.c     | function |
| input_word_counter.c     | counts the words in the user's input |
| memory_funcs.c     | contains functions to allocate memory |
| path_parserator.c     | parses the path by `:` into directories |
| print_funcs.c     | contains functions to print the list |
| string_helper_funcs.c     | contains functions to find the string length, duplicate the string, etc |
| write.c     | function that writes to standard output |

## How to Use
First step is to clone the repository into your directory
```
$ git clone https://github.com/ChristianAgha/simple_shell.git
```
Compile all the `.c` files in simple_shell
```
gcc -Wall -Wextra -Werror -pedantic -g *.c -o hsh
```
The `-g` flag is used to trace Valgrin errors, such as memory leaks and invalid reads

## Example of Use
After compiling, run the executable `./hsh`
```
$ ./hsh
$ # You are now in our version of the shell
$ ls -l
total 3
-rwxrw-r-x 1 vagrant vagrant 5345 Apr 4 14:59 hello.c
-rwxrwxrwx 1 vagrant vagrant 5343 Mar 1 22:05 julien.c
-rwxrw-r-x 1 vagrant vagrant 5542 Feb 2 09:14 holberton.c
```
## Notes
Other builtins such as aliases, history and or command separators are not supported as is currently in development.

## Known Bugs
There are no known bugs at the time.

### Authors
*Christian Agha* - [Github](https://github.com/ChristianAgha) || [Twitter](https://twitter.com/ChristyanAgha) || [email](christianagha@gmail.com)

*Kimberly Wong* - [Github](https://github.com/kjowong) || [Twitter](https://twitter.com/kjowong) || [email](kimberly.wong@holbertonschool.com)

#### Feedback and contributors welcomed. Reach out to either authors.
