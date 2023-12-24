#include <stdio.h>

int digitSum(int num) {
    int sum = 0;

    while (num > 0) {
        int digit = num % 10;
        sum += digit;
        num /= 10;
    }

    return sum;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int sumA = digitSum(a);
    int sumB = digitSum(b);

    if (sumA == sumB) {
        printf("%d %d\n", a, b);
    } else if (sumA > sumB) {
        swap(&a, &b);
        printf("%d %d\n", a, b);
    } else {
        printf("%d %d\n", a, b);
    }

    return 0;
}
