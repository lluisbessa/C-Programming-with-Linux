# Structure of makefile:

**target(what's to be done): useful archives (what's needed to do so)**<br>
&emsp;&emsp;**(tab) how to produce**

program: program.o weatherstats.o<br>
&emsp;&emsp;gcc -std=c11 -Wall -fmax-errors=10 -Wextra  program.o weatherstats.o -o program

program.o: program.c weatherstats.h<br>
&emsp;&emsp;gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c program.c -o program.o

weatherstats.o: weatherstats.c<br>
&emsp;&emsp;gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c weatherstats.c -o weatherstats.o
