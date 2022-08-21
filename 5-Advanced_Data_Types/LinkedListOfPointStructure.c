#include <stdio.h> // scanf & printf
#include <stdlib.h> // malloc & free

// Point structure declaration
struct point {
    int x;
    int y;
    struct point * next; // Argument of type struct point pointer so we can do a Linked list.
};

// Prototypes
struct point * createPoint(int, int);
struct point * appendPoint(struct point *, struct point *);
void printAndFreePoints(struct point *);

int main(void){
    // Initial variable declaration.
    int i,num,x,y; 
    struct point *start, *ptr, *end; // We need a "start" so we can free and printf from start, a "ptr" to know the current structure created and "end" for knowing the last element on the actual linked list.
    printf("How many points would you like to enter? ");
    scanf("%d", &num); // We scanf the number of points.
    for (i=0; i<num; i++){
        // We ask for the points
        printf("X: ");
        scanf("%d", &x);
        printf("Y: ");
        scanf("%d", &y);
        ptr = createPoint(x,y); // We create them and save it on the variable "ptr".
        if (i==0){ // If it's the first point we just save it to variable "start" (needed on printf and free) and "end" (needed to link linked list).
            start = end = ptr;
        } else { // If it's not the first "point", we append these "ptr" to the current "end", and return the new "end" of the list.
            end = appendPoint(end, ptr);
        }
    }
    printAndFreePoints(start); // After all the loop we printf each point and free it's memory location, we need to pass the "start" of the list, that hasn't been modified.
    return 0;
}

struct point * createPoint(int x, int y){
    struct point *ptr; // We have a pointer of the struct point so we can return our element to the linked list.
    ptr = (struct point *) malloc(sizeof(struct point)); // We allocate space in memory for the current struct point.
    ptr->x = x; // We save "x"
    (*ptr).y = y; // We save "y"
    return ptr; // And return "ptr"
}

struct point * appendPoint(struct point * end, struct point * ptr){
    end->next = ptr; // Actual end saves the next element pointer at end->next.
    return (ptr); // We return the "ptr" to the newly aggregated item to the linked list as the new end.
}

void printAndFreePoints(struct point * start){
    struct point *ptr = start; // "ptr" is "start"
    struct point *clean; // "clean" is what we finally free
    while (ptr != NULL){ // While "ptr" is not null, we continue through the list.
        printf("(%d,%d)\n", ptr->x, ptr->y);  // We printf the actual "ptr" elements "x" and "y".
        clean = ptr; // We save in "clean" the "ptr" of the printed element pointer.
        ptr = ptr->next; // We now set a new "ptr" from the next item in the list.
        free(clean); // Finally we free the previous pointer and printed already.
    }
}

