#include <stdio.h>
int fibonacci(int);
int main(void){
    int n;
    int fibonacciNum;
    printf("Enter number for fibonacci: ");
    scanf("%d",&n);
    if (n<1) {
        printf("You've entered a negative number\n");
    } else {
        fibonacciNum=fibonacci(n);
        printf("%dth fibonacci is %d\n",n,fibonacciNum);
    }
    return 0;
}
int fibonacci(int n){
    int result;
    if (n==1) {
        result = 0;
    } else if (n==2) {
        result = 1;
    } else {
        result = fibonacci(n-1) + fibonacci(n-2);
    }
    return result;
}
