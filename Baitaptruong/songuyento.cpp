#include <stdio.h>

int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int number;
        scanf("%d", &number);

        if (isPrime(number)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
