#include <stdio.h>
#include <math.h>

int sumOfDivisors(int num) {
    int sum = 1;
    int limit = sqrt(num);
	int i;
    for ( i = 2; i <= limit; i++) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i) {
                sum += num / i;
            }
        }
    }
    return sum;
}

void printNumbersWithEqualSumAndDivisors(int number1, int number2) {
    int i;
	for (i = number1; i <= number2; i++) {
        if (i != 1 && sumOfDivisors(i) == i) {
            printf("%d ", i);
        }
    }
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    if (a <= b) {
        printNumbersWithEqualSumAndDivisors(a, b);
    } else {
        printNumbersWithEqualSumAndDivisors(b, a);
    }

    return 0;
}
