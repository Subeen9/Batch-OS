#include <stdio.h>
int main(){
    int sum = 0;
    for(int i =0; i<=10; i++){
       sum = sum +i;
       printf("Summation of %d is: %d \n", i,sum); 
    }
     printf("Sum of 10 numbers is: %d \n", sum);
    return 0;
}

