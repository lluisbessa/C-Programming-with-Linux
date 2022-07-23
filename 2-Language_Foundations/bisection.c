#include <stdio.h>
int main(void){
    int list[10];
    int n=10;
    int ia=0;
    int ib=n-1;
    int mid,number,i;
    int found=0;
    printf("Enter an sorted list of 10 numbers (2 5 -3 ...): ");
    for (i=0; i<n; i++){
        scanf("%d", &list[i]);
    }
    printf("Now enter a number to search in the list: ");
    scanf("%d", &number);
    while (!found && (ia<=ib)){
        mid=(ia+ib)/2;
        if (list[mid]==number){
            found=1;
        } else if (number<list[mid]) {
            ib=mid-1;
        } else {
            ia=mid+1;
        }
    }
    if (found) {
        printf("We found %d at index %d\n",number,mid);
    } else {
        printf("%d it's not a member of the list\n",number);
    }
    return 0;
}
