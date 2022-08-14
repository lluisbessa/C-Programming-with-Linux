#include <stdio.h>
int factorial(int);
int main(void){
    // Initial declaration and initialization of variables.
    int n;
    int facto = 1;
    printf("Please enter a positive integer: ");
    scanf("%d",&n);
    if (n<0) {
        printf("%d is negative\n",n);
    } else {
        facto = factorial(n); // We enter to function where recursion is made.
        printf("%d! = %d\n", n, facto);
    }
    return 0;
}
int factorial(int n){
    if (n==0){ // End of recursion, unique known value.
        return 1;
    } else { // If we don't end the recursion, we enter in the same function like if they were nested but with the "number-1", looking for 0 so we can know value 1, and we will have (factorial(0)*1) = 1*1, then we will have factorial(1)*2 = 1*2, then we will have factorial(2)*3 = 2*3 ... until factorial(4)*5 = 24*5, that is the multiplication of all the numbers before.
        return factorial(n-1)*n; 
    }
}
