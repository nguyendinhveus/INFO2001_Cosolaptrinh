#include <stdio.h>

int isPrime(int num) {
    if (num < 2) {
        return 0;
    }

    int i;
    for (i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int numTests;
    scanf("%d", &numTests);

    while (numTests > 0) {
        int N;
        scanf("%d", &N);

        int i, number;
        for (i = 0; i < N; i++) {
            scanf("%d", &number);
            if (isPrime(number)) {
                printf("%d ", number);
            }
        }

        printf("\n");
        numTests--;
    }

    return 0;
}
