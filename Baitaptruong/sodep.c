#include <stdio.h>
#include <math.h>

int isPrime(int number) {
    if (number < 2) {
        return 0;
    }
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}
int isFibonacci(int num, int fibonacci[], int size) {
    for (int i = 0; i < size; i++) {
        if (num == fibonacci[i]) {
            return 1;
        }
    }
    return 0;
}
int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
void listBeautifulNumbers(int a, int b, int fibonacci[], int size) {
    for (int i = a; i <= b; i++) {
        if (isPrime(i) && isFibonacci(sumOfDigits(i), fibonacci, size)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
int main() {
    int fibonacci[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    int size = sizeof(fibonacci) / sizeof(fibonacci[0]);
    int a, b;
    scanf("%d %d", &a, &b);
    if (a <= b) {
        listBeautifulNumbers(a, b, fibonacci, size);
    } else {
        listBeautifulNumbers(b, a, fibonacci, size);
    }
    return 0;
}
