#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);

    int A[100];
    int even[100];
    int odd[100];
    int evenCount = 0;
    int oddCount = 0;

    for ( i = 0; i < n; i++) {
        scanf("%d", &A[i]);

        if (A[i] % 2 == 0) {
            even[evenCount] = A[i];
            evenCount++;
        } else {
            odd[oddCount] = A[i];
            oddCount++;
        }
    }


    for ( i = 0; i < evenCount; i++) {
        printf("%d ", even[i]);
    }
    printf("\n");

    for ( i = 0; i < oddCount; i++) {
        printf("%d ", odd[i]);
    }
    printf("\n");

    return 0;
}
