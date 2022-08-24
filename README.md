# C Programming with Linux

This is a GitHub repository for the algorithms I'm learning from C Programming with Linux (edx.org), separated by chapters.

Since course 4, I'll write small programs to understand better pointers, multidimensional arrays... and new libraries we're using like **stdlib.h**.

## Basic gcc usage

**$ gcc sourceProgram.c -> OUTPUT BINARY WILL BE a.out**

**$ gcc sourceProgram.c -o outputProgram -> OUTPUT BINARY WILL BE outputProgram**

**$ gcc -std=c11 -Wall -fmax-error=10 -Wextra /usr/lib/libm.a sourceProgram.c**

**-std=c11**: standard C2011   
**-Wall**: Include all possible mistakes   
**-fmax-error=10**: Output of max 10 errors and stop compiler 
**-Wextra**: Show extra errors
**-lm**: libm.a -> only use the characters after "lib", before "." and next to without space of "-l" -> -la

gcc -c -o program.o program.c

**-c**: convert program.c to machine language, don't use linker already.

## BASIC LIBRARIES 

All libraries: /usr/lib
All headers: /usr/include

/usr/lib/libm.a: Library where is stored math.h library definition OR use -lm. 


## SECURITY ON C PROGRAMS

scanf stops on newlines and on spaces. Instead use fgets (if you want even \n), or getline, or readline (only in linux).
