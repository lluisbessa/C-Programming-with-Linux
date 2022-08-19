#include <stdlib.h> // malloc()
#include <stdio.h>  // printf() & scanf()
#include <sys/select.h> // Select()
#include <string.h> // strncpy() & strncmp()

// First we declare the structure for the use inside function prototypes.
struct dateTime {
    char month[20];
    int day;
    int year;
    int second;
    int minute;
    int hour;
};

// Function prototypes
void readClock(struct dateTime *);
void printClock(struct dateTime *);
void changeDate(struct dateTime *);

int main(void){
    struct dateTime * clock; // We declare a variable "clock" that is a pointer of "struct datetime"
    clock = (struct dateTime *) malloc(sizeof(struct dateTime)); // We allocate space in the heap for the structure clock.
    readClock(clock); 
    printClock(clock);
    free(clock); // We end freeing the used heap space.
    return 0;
}

void readClock(struct dateTime *clockptr){
    // We ask for the values 
    printf("ENTER TIME NOW\n");
    printf("Year: ");
    scanf("%d", &clockptr->year); // We scanf for them pointing them with the dereference of the structure, same as "&(*clockptr).year"
    printf("Month in letters starting in capital letter \"February\": ");
    scanf("%s", (*clockptr).month); // If it's a string we don't need to use &, because a string is an array itself, and an array is a pointer to it's first element.
    printf("Day: ");
    scanf("%d", &clockptr->day);
    printf("Time \"hour minute second\": ");
    scanf("%d%d%d", &(*clockptr).hour, &clockptr->minute, &clockptr->second); // Combination of the previous dereferencing of the structure and using them as pointers.
}

void printClock(struct dateTime * now){
    int repeat = 1;
    fd_set rfds;
    struct timeval tv; // its a timeout
    /*
    struct timeval {
    time_t      tv_sec;         seconds
    suseconds_t tv_usec;        microseconds
    };
    */
    int retval; // If select returns a keypress these will change to 1.
    // While it doesn't have ascii value 48 ("0"), continue the loop.
    while (repeat!=48){
        // Watch stdin (fd 0) to see when it has input.
        FD_ZERO(&rfds);             /* This macro clears (removes all file descriptors from) set.
                                    It should be employed as the first step in initializing a
                                    file descriptor set. */
        FD_SET(0, &rfds);           /*This macro adds the file descriptor fd to set.  Adding a
                                    file descriptor that is already present in the set is a
                                    no-op, and does not produce an error. */
        tv.tv_sec = 1;  // wait for 1 second
        tv.tv_usec = 0; // wait for 1 second
        printf("%d %s %d\n", now->day, now->month, now->year);
        printf("%02d:%02d:%02d\n", now->hour, now->minute, now->second);
        printf("To stop press 0 and ENTER: ");
        fflush(stdout);
        retval = select(1, &rfds, NULL, NULL, &tv); // select(readfds, writefds, exceptfds, nfds, timeout)
        if (retval) { // Check if input
            repeat = getchar(); // Enter input ascii value in repeat, waiting for value 48
            retval = 0; // Set retval to 0 so the loop doesn't start going so fast.
        }
        now->second++; // Sum one second
        // Basic calculations for the clock
        if (now->second > 59) {
	        now->minute++;
            now->second = 0;
        }
        if (now->minute > 59) {
            now->hour++;
            now->minute = 0;
        }
        if (now->hour > 23) {
            changeDate(now); // If 24 hours, enter changeDate(struct dateTime * now).
            now->hour = 0;
        }
        system("clear"); // Clear screen on each loop.
    }
}

void changeDate(struct dateTime * date){
    // Initial variable declaration and initialization.
    char months[12][20] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int i=0;
    int month31=0;
    int month30=0;
    // We sum 1 to current day.
    date->day++;
    // Use of while to detect if month has 30 or 31 days, we leave February for later.
    while (i<12 && !month31 && !month30){
        if (strncmp(date->month, months[i], 20)==0) { // strncmp(const1, const2, size) string comparison until character 20. If month is inside 1,3,5,7... index it has 31 days.
            month31 = 1; 
        } else if (strncmp(date->month, months[i+1], 20)==0) { // If month is inside index 2,4,6,8... it has 30 days.
            month30 = 1;
            i++;
        } else { // We continue the loop by summing 2 to "i". 
            i += 2;
        }
        if (i==6) i++;
    }
    if (strncmp(date->month, "December", 20)==0 && date->day>30) { // If month is December, and it has more than 30 days:
        date->year++; // We sum one year
        strncpy(date->month,months[0],20); // We strncpy(dest, src, size) copy the element of the array at index 0 to the structure pointer of month.
        date->day = 1; // We set day to 1
    } else if (date->day > 31 && month31){ // If month has 31 days and we have 32, we change day to 1 and copy the next element of the array so we have next month.
        date->day=1;
        strncpy(date->month,months[i+1],20); 
    } else if (date->day > 30 && month30) { // Same with months with 30 days.
        date->day=1;
        strncpy(date->month,months[i+1],20);
    } else if (date->year % 4 == 0 && (date->year % 100 != 0 || date->year % 400 == 0) && strncmp(date->month, "February", 20) == 0 && date->day>29){ // Check if year is leap, if it's and it's month february, and has more than 29 days we set day to 1 and we copy March into "date->month".
        date->day = 1;
        strncpy(date->month,months[i+1],20);
    } else if (date->day > 28 && strncmp(date->month, "February", 20) == 0) { // If it's not leap, just do the same when it has 29 days.
        date->day=1;
        strncpy(date->month,months[i+1],20);
    }
}
