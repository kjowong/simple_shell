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
| env_funcs.c | functions to handle the environment |
| free_mem.c | functions that free memory allocation |
| get_builtin_func.c     | function that get the b|
| input_funcs.c | contains functions to handler user input |
| input_list_to_array.c | converts the input linked list to a double pointer |
| input_parserator.c     | function to parse the user's input |
| input_to_array.c     | function |
| input_word_counter.c     | counts the words in the user's input |
| list_to_2d_array.c     | converts env linked list into a double pointer array |
| memory_funcs.c     | contains functions to allocate memory |
| path_parserator.c     | parses the path by `:` into directories |
| print_funcs.c     | contains functions to print the list |

## How to Use
There are two ways to use the _printf function in your code.
First step is to clone the repository into your directory
```
$ git clone https://github.com/kjowong/printf.git
```
Once that is done, you can create a static library or use the -I in gcc

### Compile with a static library for _printf
Change your directory into the _printf directory in order to create your static library
```
$ cd printf
```
Compile all the `.c` files in _printf
```
gcc -Wall -Werror -Wextra -pedantic -c *.c
```
All your `.c` files should also have a corresponding `.o` file. Run the following to create your static library:
```
ar -rc lib<LIBRARY-NAME>.a *.o
```
To run your static library with your own `YOUR-FILE.c` file, use the following command:
```
gcc <YOUR-FILE>.c -L. -lib<LIBRARY-NAME> -o <OUT-NAME>
```
### Compile without a static library for _printf
Make sure the _printf directory is in the same directory as your `YOUR-FILE.c` file and then run the following command:
```
gcc -Wall -Werror -Wextra -pedantic -I $PWD/printf printf/*.c <YOUR-FILE>.c
```
The `-I` flag allows you to include the directory of the header file `holberton.h`. `$PWD/printf` takes the absolute path of the _print directory while `printf/*.c` compiles all your `.c` files in _printf

## Use in code 
### How to use _printf in your code
Please see the following example when _printf is implemented in your code:

```
#include <holberton.h>

int main(void)
{
  _printf("Let's try to print a %s sentence.\n", "simple");
  return (0):
 }
```
This is an an example output:
```
$ Let's try to print a simple sentence.
```
## Notes
This _printf function currently does not support special flags [+ , - , `, \0 , #], field, width or precision.

## Known Bugs
There are no known bugs at the time.

### Authors
*Kimberly Wong* - [Github](https://github.com/kjowong) || [Twitter](https://twitter.com/kjowong) || [email](kimberly.wong@holbertonschool.com)

*Lisa Leung* - [Github](https://github.com/lisale0) || [Twitter](https://twitter.com/lisale01) || [email](lisa.leung@holbertonschool.com)

#### Feedback and contributors welcomed. Reach out to either authors.
