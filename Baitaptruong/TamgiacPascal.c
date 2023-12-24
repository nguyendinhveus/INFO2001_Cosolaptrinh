#include <stdio.h>


int tamGiacPascal(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    else
        return tamGiacPascal(n - 1, k - 1) + tamGiacPascal(n - 1, k);
}


void inTamGiacPascal(int n) {
    int i, j; 
	for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d ", tamGiacPascal(i, j));
        }
        printf("\n");
    }
}

int main() {
    int n;

  
    scanf("%d", &n);

    inTamGiacPascal(n);

    return 0;
}
