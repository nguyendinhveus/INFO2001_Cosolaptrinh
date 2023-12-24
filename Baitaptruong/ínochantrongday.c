#include <stdio.h>

int main() {
    int numTests;
    scanf("%d", &numTests);

    while (numTests > 0) {
        int N;
        scanf("%d", &N);

        int i, number;
        for (i = 0; i < N; i++) {
            scanf("%d", &number);
            if (number % 2 == 0) {
                printf("%d ", number);
            }
        }

        printf("\n");
        numTests--;
    }

    return 0;
}
