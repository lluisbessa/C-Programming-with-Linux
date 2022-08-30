program: program.o
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra  program.o -L. -lweather -o program
program.o: program.c weather.h
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c program.c -o program.o
clean:
	rm -f program.o program
launch: program
	./program
