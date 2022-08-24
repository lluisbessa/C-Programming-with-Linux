# STEPS FOR COMPILATION OF TWO DIFFERENT SOURCES

**gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c weather.c -o weather.o**

**gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c weatherstats.c -o weatherstats.o**

**gcc -std=c11 -Wall -fmax-errors=10 -Wextra weather.o weatherstats.o -o weatherProgram**
