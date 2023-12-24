#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isPerfectSquare(int num) {
    int sqrtNum = sqrt(num);
    return (sqrtNum * sqrtNum == num);
}

int main() {
    int m, n, i;
    scanf("%d %d", &m, &n);

    if (m > n) {
        
        return 0;
    }

    int count = 0;
    int *perfectSquares = NULL;

    for (i = m; i <= n; i++) {
        if (isPerfectSquare(i)) {
            count++;
            perfectSquares = (int *)realloc(perfectSquares, count * sizeof(int));
            perfectSquares[count - 1] = i;
        }
    }

    printf("%d\n", count);

    for (i = 0; i < count; i++) {
        printf("%d\n", perfectSquares[i]);
    }

    free(perfectSquares);
    return 0;
}
