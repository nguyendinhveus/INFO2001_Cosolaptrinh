#include <stdio.h>

void printFibonacci(int n) {
    int first = 0, second = 1;
    printf("%d ", first);
	int i; 
    for ( i = 1; i < n; i++) {
        printf("%d ", second);
        int next = first + second;
        first = second;
        second = next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0 || n > 30) {
        return 0;
    }

    printFibonacci(n);

    return 0;
}
