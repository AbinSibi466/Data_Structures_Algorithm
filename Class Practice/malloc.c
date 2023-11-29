#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int *num1, *num2, *sum;

    
    num1 = (int *)malloc(sizeof(int));
    num2 = (int *)malloc(sizeof(int));
    sum = (int *)malloc(sizeof(int));

   
    if (num1 == NULL || num2 == NULL || sum == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1; 
    }

   
    printf("Enter the first number: ");
    scanf("%d", num1);

    printf("Enter the second number: ");
    scanf("%d", num2);

    
    *sum = *num1 + *num2;

    
    printf("Sum: %d\n", *sum);

   
    free(num1);
    free(num2);
    free(sum);

    return 0; 
}

