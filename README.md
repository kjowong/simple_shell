# The Shell

This project is about recreating the shell in the C language, replicating some of processes of the `sh` shell. This version will be used as `./hsh`.
## Environment
Our version of the Shell has been tested on Ubuntu 14.05.5 LTS

Tests done in VirtualBox on [Ubuntu](https://atlas.hashicorp.com/ubuntu/boxes/trusty64) via [Vagrant](https://www.vagrantup.com/)(1.9.1)

## Repository Breakdown
Once cloned over, the repository will contain the following files:

|   **File**    |  **Decription**                       |
|---------------|---------------------------------------|
| shell.h   | header file with prototypes           |
| printf.c      | contains main printf function         |
| _putchar.c     | contains putchar function             |
| string_specifiers.c | contains functions for **s** and **c** |
| string_spec_helpers.c     | contains functions to help with string functions in string_specifiers.c|
| signed_decimal_specifiers.c | contains functions for **d** and **i** |
| unsigned_specifiers.c | contains functions for **o**, **u**, **x**, **X** |
| binary_specifier.c     | contains functions for **b**|
| pointer_address_specifiers.c | contains functions for **p** |
| write_percent specifiers.c | contains functions for **'%'** |
| write_buffer.c     | contains functions to write to the buffer |
| reset_buffer.c     | contains functions to reset the buffer |
| rev_string.c     | contains functions to reverse strings |
| rot_13.c     | contains functions to converts a string to rot13 format |

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
