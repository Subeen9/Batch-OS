#include <stdio.h>

int main() {
    int num = 10;
    long long result = 1;

    for (int i = 1; i <= num; i++) {
        result *= i;
        printf("Factorial of %d is %lld\n", i, result); 
    }

    printf("The factorial of %d is %lld\n", num, result);
    return 0;
}
