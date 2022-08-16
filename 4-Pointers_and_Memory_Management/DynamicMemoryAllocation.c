/*

IN THIS PROGRAM I WILL TAKE A NUMBER OF NAMES AND GRADES YOU WOULD LIKE TO SUBMIT, SCANF THEM, SHOW THEM, AND CALCULATE THE AVERAGE.

*/


#include <stdio.h>
#include <stdlib.h> // Library for malloc() and free()

void getNamesAndGrades(char **, int *, int);
void printNamesAndGrades(char **, int *, int);
double averageCalc(int *, int);

int main(void){
    // Initial variable declaration
    int numGrades; // Normal int
    int * grades;  // Int pointer
    char ** names; // Pointer of a char pointer
    double average; // Double for floating point numbers
    printf("Please enter number of grades and names you would like to submit: ");
    scanf("%d", &numGrades);
    grades = (int *) malloc(numGrades*sizeof(int)); // Dinamically allocate memory on the heap, creating an array of ints.
    names = (char **) malloc(numGrades*sizeof(char *)); // Dinamycally allocate memory on the heap, creating an array of char pointers.
    getNamesAndGrades(names, grades, numGrades);
    printf("\n\n");
    printNamesAndGrades(names, grades, numGrades);
    average=averageCalc(grades, numGrades);
    printf("\nThe average of the class is: %.2lf\n", average);
    free(names); // Freeing of the heap.
    free(grades);
    return 0;
}

void getNamesAndGrades(char ** names, int * grades, int numGrades){
    // Initial variable declaration
    int i;
    printf("Please input names and grades one per line, for example \"Rosa 7\" (NAMES <= 10 LETTERS):\n");
    for (i=0; i<numGrades; i++){
        names[i] = (char *) malloc(11*sizeof(char)); // Allocate space in each char pointer so we can store the names.
        scanf("%s %d", names[i], grades+i); // Getting each name and grade and storing them in it's respective pointers.
    }
}

void printNamesAndGrades(char ** names, int * grades, int numGrades){
    // Initial variable declaration
    int i;
    printf("You've entered:\n");
    for (i=0; i<numGrades; i++){
        printf("%s %d\n", names[i], *(grades+i)); // Printing the names and grades side by side you've entered.
    }
}

double averageCalc(int * grades, int numGrades){
    // Initial variable declaration
    double average = 0.0;
    int i;
    for (i=0; i<numGrades; i++){
        average += *(grades+i); // Calculate average by summing the dereference of each grade in the list.
    }
    average = average/numGrades; // Dividing the sum between the number of grades.
    return average;
}
