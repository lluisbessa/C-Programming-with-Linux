#include <stdio.h>
int main(void){
    int list[10];
    int n=10;
    int i,number;
    int found=0;
    printf("Enter an unsorted list of 10 numbers (2 5 -3 ...): ");
    for (i=0; i<n; i++){
        scanf("%d",&list[i]);
    }
    printf("Enter a number to search in the list: ");
    scanf("%d", &number);
    i=0;
    while (i<n && !found) {
        if (list[i]==number){
            found=1;
        } else {
            i++;
        }
    }
    if (found) {
        printf("We found %d at index %d\n",number,i);
    } else {
        printf("%d it's not a member of the list\n",number);
    }
    return 0;
}

