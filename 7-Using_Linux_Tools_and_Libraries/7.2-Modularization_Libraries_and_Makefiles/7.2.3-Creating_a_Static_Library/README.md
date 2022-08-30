# (-) STATIC LIBRARY VS (+) DYNAMIC LIBRATY
- Linker finds all used library functions (such as printf(), sqrt(), etc) and copies them into your executable file
+ Linked dynamically at run-time by the OS: every program that accesses the library uses the same copy.

- Libraries have the extension .a (Linux) and .lib (Windows).
+ Libraries have the extension .so (Linux) and .dll (Windows). 

- Executable is a larger file, needing more disk space and main memory.
+ Executable only contains the name of (a link to) the library.

- If library changes, the executable does not automatically update - needs to be relinked.
+ If library changes, the executable will automatically use the new library code.

- If library becomes incompatible with your code, your executable will still run just fine, as long as you don't relink.
+ If library becomes incompatible with your code, your executable will no longer run.

- Library access is faster.
+ Dynamic querying of symbols take time.

# How to make a static library (assuming same directory)
## Compile library files
gcc -c part1.c -o part1.o 
gcc -c part2.c -o part2.o
...

## Create library
ar rcs libmylib.a part1.o part2.o ...

## Compile main program
gcc -c program.c -o program.o

## Link library to main program
gcc -o program program.o -L. -lmylib


# How to make a dynamic library
gcc -fpic part1.c -o part1.o 
gcc -fpic part2.c -o part2.o
...

## Create library (assuming same directory)
gcc -shared -o libmylib.so part1.o part2.o ...

## Compile main program
gcc -c program.c -o program.o

## Link library to main program
gcc -o program program.o -L. -lmylib 

(Add library path to environment variable)
export LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH
