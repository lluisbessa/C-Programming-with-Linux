#include <stdio.h>
#include <math.h>

int main(void){
    double d;
    double dSquare;
    double dSqrt;
    printf("Please enter a number:\n");
    scanf("%lf", &d);
    dSquare = pow(d, 2);
    dSqrt = sqrt(d);
    printf("%.2lf square = %.2lf.\n", d, dSquare);
    printf("%.2lf square root = %.2lf.\n", d, dSqrt);
    return 0;
}
