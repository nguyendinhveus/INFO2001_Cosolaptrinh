#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    if (b != 0) {
        int sum = a + b;
        int difference = a - b;
        long long product = (long long)a * b;
        int quotient_integer = a / b;
        int remainder = a % b;
        float quotient_float = (float) a / b;
        printf("%d\n%d\n%lld\n%d\n%d\n%.2f\n", sum, difference, product, quotient_integer, remainder, quotient_float);
    } else {
        printf("0\n");
    }

    return 0;
}
