#include <stdio.h> // scanf and printf.
#include <stdlib.h> // malloc and free.

// Struct declaration.
struct digit {
    int num;
    struct digit * next; // Pointer to same structure to create the linked list.
};

// Function prototypes.
struct digit * readDigits();
struct digit * createDigit(int);
struct digit * append(struct digit *, struct digit *);
void printDigits(struct digit *);
struct digit * reverseDigit(struct digit *);
struct digit * insertAtFront(struct digit *, struct digit *);
struct digit * sortDigits(struct digit *);
struct digit * insertIntoSorted(struct digit *, struct digit *);
void freeNums(struct digit *);

int main(void){
    struct digit * start, * backwards, * sorted; // We create various pointers for all the types of linked list we will use.
    start = readDigits();
    printf("You've entered:\n");
    printDigits(start);
    backwards = reverseDigit(start);
    printf("Backwards you've entered:\n");
    printDigits(backwards);
    printf("Sorted you've entered:\n");
    sorted = sortDigits(start);
    printDigits(sorted);
    freeNums(start);
    freeNums(backwards);
    freeNums(sorted);
    return 0;
}

struct digit * readDigits(){ 
    // Initial variable declaration.
    char c;
    int d;
    struct digit * start, *end, *ptr;
    start = NULL;
    printf("Enter a long number: ");
    scanf("%c", &c); // We scan character by character and convert them to it's number.
    while (c != '\n') {
        d = c - 48; // ASCII VALUE - 48 = NUMBER. ASCII 0 = 48, 48-48 =  int 0.
        if (start == NULL) { // The first case is when there is no number in the list, so start is NULL.
            start = end = createDigit(d); // In this case, start and end will be the same returned structure.
        } else {
            ptr = createDigit(d);  // We create a new ptr of struct digit.
            end = append(end,ptr); // We append this new ptr to the end to the list and convert this ptr to the new end.
        }
        scanf("%c", &c); // We continue scanning for new digits.
    }
    return start; // If while loop finishes, we return the start of the structure.
}

struct digit * createDigit(int dig) { // Function to declarate a new structure with malloc and save into it the num passed to this function.
    struct digit * ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig; // Save the digit to it's place in the structure.
    return ptr; // Finally it returns the new structure digit with the new num.
}

struct digit * append(struct digit * end, struct digit * ptr){
    end->next = ptr; // The next number to end is the new ptr.
    return ptr; // The new end is ptr.
}

void printDigits(struct digit * start){ // To print digits.
    while (start != NULL){ // While start is not null, we continue the while loop.
        printf("%d",start->num); // We print the num saved by start.
        start = start->next; // We advance start to the next struct digit in the linked list.
    }
    printf("\n"); // Finally we enter a new line.
}

struct digit * reverseDigit(struct digit * start){ // Function to create the number backwards.
    // Initializee the variables.
    struct digit * backward = NULL; // We initialize backward as null, just for the case where we don't enter the if neither the while and backward doens't have a value.
    struct digit *newDigit;
    if (start != NULL) { // If start is not null let's operate with him.
        backward = createDigit(start->num); // The new backward start is the first element of the linked list.
        start = start->next; // We advance start by 1.
    }
    while (start != NULL) { 
        newDigit = createDigit(start->num); // We create a struct digit pointer from the next element in the normal linked list.
        backward = insertAtFront(backward, newDigit); // Here comes the magic, where instead of saving the element after these backward start, we insert it at front and return the new backward start.
        start = start->next; // Advance until a NULL character.
    }
    return backward; // Finally return the backward list.
}

struct digit * insertAtFront(struct digit * backward, struct digit * newDig){
    newDig->next = backward; // The next position of newDigit is backward start.
    return newDig; // The new start will be newDigit.
}

struct digit * sortDigits(struct digit * start){ // Function to go through all the digits.
    struct digit * sorted = NULL; // We initialize the start of sorted as null just in case we don't enter the if neither the while.
    struct digit * newDigit; 
    if (start != NULL) {
    sorted = createDigit(start->num); // Create a first digit and store it into sorted.
    start = start->next; // Go to the next position of the linked list start.
    }
    while ((start != NULL)){ // While start is not null...
        newDigit = createDigit(start->num); // Create a copy of the digit and save it into newDigit.
        sorted = insertIntoSorted(sorted, newDigit); // Function that returns any new start of the sorted linked list, and inserts newDigit at the right position.
        start = start->next; // Go to the next position of the linked list start.
    } 
    return sorted;
}

struct digit * insertIntoSorted(struct digit * start, struct digit * newDigit){
    struct digit *ptr = start; // We need a pointer to the current element.
    struct digit *prev = NULL; // We need to know the previous element just in case the number is between two numbers and we need to break their relationship.
    while ((ptr != NULL) && (ptr->num < newDigit->num)){ // Advance while ptr is not null and the num pointer by ptr is less than the newDigit->num.
        prev = ptr;
        ptr = ptr->next;
    }
    if (prev == NULL){ // If prev is null, we know our number is the lesser of the linked list, because we didn't enter the while inside the sorted list.
        start = insertAtFront(start, newDigit); // In this case we just need to insert the number at front of the list.
    } else { // Else the number is at the end or on the mid, this is when "prev" number is useful.
        prev->next = newDigit; // prev->next will be the newDigit, so if we had 1,3,9 and a new number 5. The loop would break with the prev as 3 and the ptr as 9. So we would know that we need to insert the number between them.
        newDigit->next = ptr; // Because we don't have a link to ptr in the linked list know, just the current variable ptr is in our hands, we point newDigit->next to ptr so we don't lose any digit in the linked list.
    }
    return start; // Finally we return the sorted list.
}

void freeNums(struct digit * start){ // To free the elements.
    struct digit *ptr = start; // We declare a variable to know the next element on the list.
    struct digit *clean; // We declare "clean", that will save ptr just before ptr going to it's next position and freeing clean.
    while (ptr != NULL){
        clean = ptr; // We save ptr at clean.
        ptr = ptr->next; // We advance ptr by one struct in the linked list so we know where is the next element before we free the previous element saved at clean, so we don't lose the full list pointers.
        free(clean); // Finally we free each pointer starting from it's start. 
    }
}

