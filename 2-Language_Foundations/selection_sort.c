#include <stdio.h>
int main(void){
    // Initial variable declaration and initialization.
    int list[10];
    int n=10;
    int i,j,min,swap,pos;
    printf("Enter an unsorted list of 10 numbers (2 5 -3 ...): ");
    for (i=0; i<n; i++){
        scanf("%d",&list[i]);
    }
    for (i=0; i<n; i++) { // Initial loop setting index "i" to be the minimum number.
        min=i;
        for (j=i+1; j<n; j++) { // We search for each number looking for a number less than the previous minimum.
            if (list[j] < list[min]) { // If found a lesser number, we set "min" to index "j".
                min=j;
            }
        }
        swap=list[min]; // After each nested iteration, we change the lesser number with the index "i", we do this for each number in the array.
        list[min]=list[i];
        list[i]=swap;
    }
    printf("Sorted list:\n");
    for (i=0; i<n; i++){
        printf("%d ",list[i]);
    }
    printf("\n");
    return 0;
}

