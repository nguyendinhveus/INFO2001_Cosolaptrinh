#include <stdio.h>

int main() {
    int N;
    bool isPrime = true;

    printf("Nhap so nguyen duong N: ");;
    scanf("%d", &N);

    if (N <= 1) {
        isPrime = false;
    } else {
        for (int i = 2; i <= N / 2; i++) {
            if (N % i == 0) {
                isPrime = false;
                break;
            }
        }
    }

    if (isPrime) {
        printf("N la so nguyen to");
    } else {
    	printf("N khong phai la so nguyen to");
    }

    return 0;
}
