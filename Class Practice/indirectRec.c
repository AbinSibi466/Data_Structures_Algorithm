#include <stdio.h>

void functionB(int n); // Forward declaration

void functionA(int n) {
    if (n > 0) {
        printf("%d ", n);
        functionB(n - 1);
    }
}

void functionB(int n) {
    if (n > 1) {
        printf("%d ", n);
        functionA(n / 2);
    }
}

int main() {
    int num = 10;
    printf("Indirect Recursion: ");
    functionA(num);
    return 0;
}
  