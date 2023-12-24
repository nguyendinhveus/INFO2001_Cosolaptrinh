#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 500

void reverse_string(char* str) {
    int length = strlen(str);
    int i, j;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void add_large_numbers(char* num1, char* num2, char* result) {
    int carry = 0;
    int length1 = strlen(num1);
    int length2 = strlen(num2);
    int max_length = (length1 > length2) ? length1 : length2;
    int i, digit_sum;

    // Kh?i t?o k?t qu? là chu?i r?ng
    result[0] = '\0';

    for (i = 0; i < max_length; i++) {
        int digit1 = (i < length1) ? (num1[length1 - i - 1] - '0') : 0;
        int digit2 = (i < length2) ? (num2[length2 - i - 1] - '0') : 0;

        digit_sum = digit1 + digit2 + carry;
        carry = digit_sum / 10;
        digit_sum = digit_sum % 10;

        // Chèn ch? s? tính ðý?c vào ð?u k?t qu?
        result[i] = digit_sum + '0';
    }

    if (carry > 0) {
        // N?u c?n carry sau khi ð? c?ng h?t các ch? s?, chèn nó vào ð?u k?t qu?
        result[i] = carry + '0';
        i++;
    }

    result[i] = '\0';
    reverse_string(result);
}

int main() {
    int num_tests;
    scanf("%d", &num_tests);

    while (num_tests > 0) {
        char num1[MAX_DIGITS + 1];
        char num2[MAX_DIGITS + 1];
        char result[MAX_DIGITS + 2];

        scanf("%s", num1);
        scanf("%s", num2);

        add_large_numbers(num1, num2, result);

        printf("%s\n", result);

        num_tests--;
    }

    return 0;
}
