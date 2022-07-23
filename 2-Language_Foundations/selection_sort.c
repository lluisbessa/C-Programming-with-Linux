#include <stdio.h>
int main(void){
    int list[10];
    int n=10;
    int i,j,min,swap,pos;
    printf("Enter an unsorted list of 10 numbers (2 5 -3 ...): ");
    for (i=0; i<n; i++){
        scanf("%d",&list[i]);
    }
    for (i=0; i<n; i++) {
        min=i;
        for (j=i+1; j<n; j++) {
            if (list[j] < list[min]) {
                min=j;
            }
        }
        swap=list[min];
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

