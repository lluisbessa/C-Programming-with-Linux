#include <stdio.h>
int main(void){
    int i, n;
    int facto=1;
    printf("Please enter a positive integer: ");
    scanf("%d",&n);
    for (i=1; i<=n; i++){
        facto=i*facto;
    }
    if (n<0) {
        printf("%d is negative\n",n);
    } else {
        printf("%d! = %d\n", n, facto);
    }
    return 0;
}
