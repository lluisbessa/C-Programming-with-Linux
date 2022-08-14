#include <stdio.h>
int main(void){
    // Initial variable declaration and initialization.
    int list[10];
    int n=10;
    int ia=0;
    int ib=n-1;
    int mid,number,i;
    int found=0;
    printf("Enter a sorted list of 10 numbers (2 5 -3 ...): ");
    for (i=0; i<n; i++){
        scanf("%d", &list[i]);
    }
    printf("Now enter a number to search in the list: ");
    scanf("%d", &number);
    while (!found && (ia<=ib)){ // If not found and "ia" is not greater than "ib" continue with the loop of bisection.
        mid=(ia+ib)/2; // Declaration of mid, the index where do we search the number.
        if (list[mid]==number){ // If we found the number convert "found" to 1 (True)
            found=1;
        } else if (number<list[mid]) { // If number is less than the number at index "mid", "ib" will now be "mid-1" because we dont need to get to mid index anymore.
            ib=mid-1;
        } else { // Same as the comment before but if the number is greater than the found at index "mid".
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
