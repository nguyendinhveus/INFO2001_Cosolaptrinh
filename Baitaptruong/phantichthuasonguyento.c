#include <stdio.h>

void primeFactorization(int num) {
    int i; 
	for ( i = 2; i <= num; i++) {
        while (num % i == 0) {
            printf("%d ", i);
            num /= i;
        }
    }
}

int main() {
    int t, i;
    scanf("%d", &t);

    for ( i = 0; i < t; i++) {
        int num;
        scanf("%d", &num);

        primeFactorization(num);
        printf("\n");
    }

    return 0;
}
