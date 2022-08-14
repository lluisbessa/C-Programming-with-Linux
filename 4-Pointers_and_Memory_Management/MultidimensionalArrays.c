#include <stdio.h>

void readInt(int **, int, int);
void readString(char  [5][11], int);
void printInt(int **, int);
void printString(char [5][11], int);


int main(void){
    int array1[4];
    int array2[4];
    int * MultidimensionalInt[2] = {array1, array2};
    char MultidimensionalChar[5][11];
    printf("Please enter 4 integers for first array: ");
    readInt(MultidimensionalInt, 4, 0);
    printf("Please enter 4 integers for second array: ");
    readInt(MultidimensionalInt, 4, 1);
    printf("Please enter a string of 5 words with maximum 10 characters: ");
    readString(MultidimensionalChar, 5);
    printInt(MultidimensionalInt, 4);
    printString(MultidimensionalChar, 5);
    return 0;
}

void readInt(int ** ptr, int size, int index){
    int i;
    for (i=0; i<size; i++){
        scanf("%d", (* (ptr+index)+i));
    }
}

void readString(char ptr[5][11], int size){
    int i;
    for (i=0; i<size; i++){
        scanf("%s", ptr[i]);
    }
}

void printInt(int ** ptr, int size){
    int i,j;
    printf("The two arrays together have these elements:\n");
    for (i=0; i<2; i++){
        for (j=0; j<size; j++){
            printf("%d ", * (* (ptr+i)+j));
        }
    }
    printf("\n");
}
void printString(char ptr[5][11], int size){
    int i;
    printf("You've entered the string: \n");
    for (i=0; i<size; i++){
        printf("%s ", ptr[i]);
    }
    printf("\n");
}
