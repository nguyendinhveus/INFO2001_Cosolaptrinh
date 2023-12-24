#include <stdio.h>

int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int test_cases, i ;
    scanf("%d", &test_cases);
	
    for ( i = 0; i < test_cases; i++) {
        int n;
        scanf("%d", &n);
        int digit_sum = sumOfDigits(n);
        printf("%d\n", digit_sum);
    }

    return 0;
}
