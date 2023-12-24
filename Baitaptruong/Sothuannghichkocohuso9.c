#include <stdio.h>

int isPalindrome(int num) {
    int temp = num;
    int reverse = 0;

    while (temp > 0) {
        reverse = reverse * 10 + temp % 10;
        temp /= 10;
    }

    return (reverse == num);
}

int countPalindromes(int N, int palindromes[]) {
    int count = 0;
    int num; 
	for ( num = 2; num < N; num++) {
        if (num % 10 != 9 && isPalindrome(num)) {
            palindromes[count] = num;
            count++;
        }
    }
    return count;
}

int main() {
    int N;
    scanf("%d", &N);

    if (N > 9999) {
        
        return 0;
    }

    int palindromes[1000];
    int count = countPalindromes(N, palindromes);
	int i; 
    for ( i = 0; i < count; i++) {
        printf("%d ", palindromes[i]);
    }

    printf("\n%d\n", count);

    return 0;
}
