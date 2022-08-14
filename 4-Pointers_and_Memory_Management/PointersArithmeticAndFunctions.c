#include <stdio.h>

void read(int *, int);
void print(int *, int);
void bubbleSort(int *, int);

int main(void){
    int array[4];
    int * ptr = array; // This ptr could be also be the array variable itself since it only stores the first direction in memory of the array. 
    printf("Please enter 4 integers separated by a space: ");
    read(ptr, 4);
    printf("The array has these elements:\n");
    print(array, 4);
    bubbleSort(ptr, 4);
    printf("The result after sorting the array from max to min using bubbleSort algorithm is: \n");
    print(array, 4);
    return 0;
}

void read(int * ptr, int size){
    int i;
    for (i=0; i<size; i++){
        scanf("%d", (ptr+i));
    }
}

void print(int * array, int size){
    int i;
    for (i=0; i<size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bubbleSort(int * ptr, int size){
    int i,j,swap;
    int * swapAdr= &swap;
    for (i=0; i<size-1; i++){
        for (j=0; j<size-1; j++){
            if (*(ptr+j) < *(ptr+j+1)){
                * swapAdr = * (ptr+j);
                * (ptr+j) = * (ptr+j+1);
                * (ptr+j+1) = * swapAdr;
            }
        }
    }
}
