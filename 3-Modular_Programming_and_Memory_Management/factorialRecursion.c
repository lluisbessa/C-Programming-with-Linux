#include <stdio.h>
int factorial(int);
int main(void){
    int n;
    int facto = 1;
    printf("Please enter a positive integer: ");
    scanf("%d",&n);
    if (n<0) {
        printf("%d is negative\n",n);
    } else {
        facto = factorial(n);      
        printf("%d! = %d\n", n, facto);
    }
    return 0;
}
int factorial(int n){
    if (n==0){
        return 1;
    } else {
        return factorial(n-1)*n;
    }
}
