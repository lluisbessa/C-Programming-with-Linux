# Structure of makefile:

**target(what's to be done): useful archives (what's needed to do so)**<br>
&emsp;&emsp;**(tab) how to produce**

program: program.o weatherstats.o<br>
&emsp;&emsp;gcc -std=c11 -Wall -fmax-errors=10 -Wextra  program.o weatherstats.o -o program

program.o: program.c weatherstats.h<br>
&emsp;&emsp;gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c program.c -o program.o

weatherstats.o: weatherstats.c<br>
&emsp;&emsp;gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c weatherstats.c -o weatherstats.o

**clean**:<br>
&emsp;&emsp;(command to remove .o files and program)

**clean**:<br>
&emsp;&emsp;rm -f weatherstats.o program.o program

**launch**:program<br>
&emsp;&emsp;./program (if we call make launch in the CLI, gcc will compile the program and execute it)
