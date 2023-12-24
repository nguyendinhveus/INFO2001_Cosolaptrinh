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

int main() {
    int t, i;
    scanf("%d", &t);

    for ( i = 0; i < t; i++) {
        int num;
        scanf("%d", &num);

        int sum = digitSum(num);

        if (sum % 10 == 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
