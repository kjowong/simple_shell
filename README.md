# BombShell

This project is about recreating the shell in the C language, replicating some of processes of the `sh` shell. This version will be used as `./hsh`. This project is a partner project that was completed when both partners paired programmed - this project was originally on one repository until grades were released. Once grades were released, this version was forked over. (No changes were made afterwards)

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
| get_builtin_func.c     | function that get the builtins through a function pointer|
| input_funcs.c | contains functions to handler user input |
| input_list_to_array.c | converts the input linked list to a double pointer |
| input_parserator.c     | function to parse the user's input |
| input_to_array.c     | function that converts the string input into a double pointer array |
| input_word_counter.c     | counts the words in the user's input |
| memory_funcs.c     | contains functions to allocate memory |
| path_parserator.c     | parses the path by `:` into directories |
| print_funcs.c     | contains functions to print the list |
| string_helper_funcs.c     | contains functions to find the string length, duplicate the string, etc |
| string_helper_funcs2.c     | contains a function that concatenates two strings |
| write.c     | function that writes to standard output |

## Description of File Structure
1. [build_all_variables.c](build_all_variables.c) - Builds all the variables needed for each function:
  * ``*build_all_variables()`` - builds all the variables needed for each function such as when building a linked list
2. [builtin_funcs.c](builtin_funcs.c) - Includes two builtin functions:
  * ``print_env()`` - Prints the user's current environment
  * ``_setenv()`` - Allows the user to create or modify an environmental variable.
3. [cmd_executor.c](cmd_executor.c) - Includes functions to execute the binary executable programs:
  * ``full_path_executor()`` - executes the binary executable if the user inputs the full path. For example: /bin/ls
  * ``path_cmd_executor()`` - executes the binary executable if the user inputs just the command. For example: ls
4. [env_funcs.c](env_funcs.c) - Includes all functions that deal with the environment:
  * ``add_env_node()`` - creates a linked list from the user's current environment
  * ``create_env_list()`` - creates a linked list from the ``environ`` variables.
5. [envlist_to_array.c](envlist_to_array.c) - Includes function to convert the environmental variable linked list into a double pointer array:
  * ``conv_list_to_array()`` - Converts the environmental linked list into a double pointer array
6. [free_mem.c](free_mem.c) - Includes functions to free memory:
  * ``free_input_list()`` - Frees the input linked list (Currently not in use)
  * ``free_env_list()`` - Frees the environmental variable linked list
  * ``free_env_array()`` - Frees the double pointer environmental variable array
  * ``free_path_array()`` - Frees the double pointer path array
  * ``free_mem()`` - Function that calls all the free functions
7. [get_builtin_func.c](get_builtin_func.c) - Includes a function to get the builtin functions:
  * ``*get_builtin_func()`` - Function pointer that points to the builtin function the user inputs
8. [input_funcs.c](input_funcs.c) - Include a function that handle the user's input:
  * ``*add_node_end`` - Adds the user's input into a linked list (currently not in use).
9. [input_list_to_array.c](input_list_to_array.c) - Includes a function to convert the input linked list into a double pointer array:
  * ``conv_inputlist_to_array()`` - function to convert the input linked list into a double pointer array (currently not in use).
10. [input_parserator.c](input_parserator.c) - Includes a function to parse the user's input:
* ``*input_parserator()`` - a function to parse the user's input
11. [input_to_array.c](input_to_array.c) - Includes a function that takes in the input and converts to a double pointer array:
  * ``**input_to_array()`` - takes in the user input as a string and converts to a double pointer array
12. [input_word_counter.c](input_word_counter.c) - Counts the tokens in the user input:
  * ``input_token_count()`` - counts the amount of tokens in the input
13. [memory_funcs.c](memory_funcs.c) - Includes functions for memory:
  * ``*_grand_malloc()`` - allocates memory, filling area with null bytes '\0'
  * ``*_memcopy()`` -  copies the memory area
  * ``*_memset() - function that fills the memory with a constant byte
14. [path_parserator.c](path_parserator.c) - Includes functions to parse the path:
  * ``path_folder_counter()`` - counts the amount of folders in the path
  * ``path_parserator()`` -  converts the environmental linked list into a double pointer array
15. [print_funcs.c](print_funcs.c) - Includes functions to print the environmental list:
  * ``print_env_list()`` - function that prints the environmental list
  * ``print_input_list()`` -  function that prints the input list
16. [shell.c](shell.c) - File includes the main shell function and signal handler:
  * ``main()`` - main shell function
  * ``signal_handler()`` -  function that handles the signal ^C
17. [shell.h](shell.h) - Header file that includes prototypes and structs
18. [string_helper_funcs.c](string_helper_funcs.c) - Includes functions that help the basic functionality for the shell:
  * ``_strcmp()`` - function that compares the strings
  * ``_strncmp()`` -  function that compares the strings up to at most the first n bytes of string 1
  * ``_strcmp_env()`` -  function that compares the strings for the environmental variables
  * ``*_strdup()`` -  function that duplicates the string
  * ``_strlen()`` -  function that finds the length of the string
19. [string_helper_funcs2.c](string_helper_funcs2.c) - Includes additional functions that help the basic functionality for the shell:
  * ``*_strncat_env()`` - function that concatenates two strings
20. [write_func.c](write_func.c) - Includes a function that writes to standard output:
  * ``_write()`` - function that writes to standard output
21. [AUTHORS](AUTHORS) - List of contributors.
22. [man_1_simple_shell](man_1_simple_shell) - Manual page for the shell.

## How to Use
First step is to clone the repository into your directory
```
$ git clone https://github.com/ChristianAgha/simple_shell.git
```
Compile all the `.c` files in simple_shell
```
gcc -Wall -Wextra -Werror -pedantic -g *.c -o hsh
```
The `-g` flag is used to trace Valgrind errors, such as memory leaks and invalid reads

## Example of Use
After compiling, run the executable `./hsh`
```
$ ./hsh
$ # You are now in our version of the shell
$ ls -l
total 3
-rwxrw-r-x 1 vagrant vagrant 5345 Apr 4 14:59 hello.c
-rwxrwxrwx 1 vagrant vagrant 5343 Mar 1 22:05 julien.c
-rwxrw-r-x 1 vagrant vagrant 5542 Feb 2 09:14 nutella.c
```
## Notes
Other builtins such as aliases, history, and or command separators are not supported and are currently in development.

## Known Bugs
There are no known bugs at the time.

### Authors
*Christian Agha* - [Github](https://github.com/ChristianAgha) || [Twitter](https://twitter.com/ChristyanAgha) || [email](christianagha@gmail.com)

*Kimberly Wong* - [Github](https://github.com/kjowong) || [Twitter](https://twitter.com/kjowong) || [email](kjowong@gmail.com)

#### Feedback and contributors welcomed. Reach out to either authors.

