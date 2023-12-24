#include <stdio.h>

void printDecimalFraction(int N) {
    if (N == 1) {
        printf("1\n");
        return;
    }

    int dividend = 1;
    int divisor = N;
    int decimalPlaces = 15;

    printf("0.");
    while (decimalPlaces > 0) {
        dividend *= 10;
        int quotient = dividend / divisor;
        printf("%d", quotient);
        dividend = dividend % divisor;
        decimalPlaces--;
    }
    printf("\n");
}

int main() {
    int numTests;
    printf("Nh?p s? b? test: ");
    scanf("%d", &numTests);

    for (int i = 0; i < numTests; i++) {
        int N;
        printf("Nh?p s? nguyên dýõng: ");
        scanf("%d", &N);
        printDecimalFraction(N);
    }

    return 0;
}
