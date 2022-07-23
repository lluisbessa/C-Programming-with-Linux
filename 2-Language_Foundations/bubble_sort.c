#include <stdio.h>
int main(void){
    int list[10];
    int n=10;
    int i,j,swap;
    printf("Enter an unsorted list of 10 numbers (2 5 -3 ...): ");
    for (i=0; i<n; i++){
        scanf("%d",&list[i]);
    }
    for (i=0; i<n-1; i++) {
        for (j=0; j<n-1; j++) {
            if (list[j] > list[j+1]) {
                swap = list[j];
                list[j] = list[j+1];
                list[j+1] = swap;
            }
        }
    }
    printf("Sorted list:\n");
    for (i=0; i<n; i++){
        printf("%d ",list[i]);
    }
    printf("\n");
    return 0;
}
