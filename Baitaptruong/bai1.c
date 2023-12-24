#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);

    int numbers[n];
    
    for ( i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
        long long square = (long long)numbers[i] * numbers[i];
        printf("%lld \n", square);
    }

    return 0;
}
