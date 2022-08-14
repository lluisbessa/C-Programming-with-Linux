#include <stdio.h>
int fibonacci(int);
int main(void){
    // Initial declaration and initialization.
    int n;
    int fibonacciNum;
    printf("Enter number for fibonacci: ");
    scanf("%d",&n);
    if (n<1) {
        printf("You've entered a negative number\n");
    } else {
        fibonacciNum=fibonacci(n); // We enter the recursion.
        printf("%dth fibonacci is %d\n",n,fibonacciNum);
    }
    return 0;
}
int fibonacci(int n){
    int result;
    if (n==1) { // We have two known values, that are the minimum, because we will use the sum of "n-1"+"n-2"= fibonnacci(n).
        result = 0;
    } else if (n==2) {
        result = 1;
    } else {
        result = fibonacci(n-1) + fibonacci(n-2); // While we don't arrive to numbers 0 and 1, we go through nested functions waiting to come back with the initial sum, 0,1 = 0+1 -> 0,1,1 = 1+1 -> 0,1,1,2 = 1+2 -> 0,1,1,2,3 = 2+3 -> 0,1,1,2,3,5...
    }
    return result;
}
