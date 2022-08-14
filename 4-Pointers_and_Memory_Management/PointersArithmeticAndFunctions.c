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
        scanf("%d", (ptr+i)); // We can use the pointer of the array, and suming "i" to it, that in these case is int, so 0xfff4 + 1 in reality is 0xfff4+4bytes in memory, or the size you get for the data type using sizeof().
    }
}

void print(int * array, int size){
    int i;
    for (i=0; i<size; i++){
        printf("%d ", array[i]); // "array" itself is a pointer to first number of the array, we can iterate through the array by using "[i]".
    }
    printf("\n");
}

void bubbleSort(int * ptr, int size){ // Application of bubble sort with pointers. 
    int i,j,swap;
    int * swapAdr= &swap; // We use swap but with it's pointer, we can find it by declaring "int * swapAdr (Declaration of a pointer)" = "&swap (& way to know the location in memory of the variable)"-
    for (i=0; i<size-1; i++){
        for (j=0; j<size-1; j++){
            if (*(ptr+j) < *(ptr+j+1)){
                * swapAdr = * (ptr+j); // "* variable" means the dereference of the pointer so we can store an int in these case. Note that when we use "dataType * variable" it's not a dereference, instead a pointer of int declaration.
                * (ptr+j) = * (ptr+j+1);
                * (ptr+j+1) = * swapAdr;
            }
        }
    }
}
