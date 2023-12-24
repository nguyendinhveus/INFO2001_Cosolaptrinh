#include <stdio.h>
#include <ctype.h>

int countWords(char str[]) {
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        
        while (isspace(str[i])) {
            i++;
        }

        
        if (str[i] != '\0') {
            count++;

            while (!isspace(str[i]) && str[i] != '\0') {
                i++;
            }
        }
    }

    return count;
}

int main() {
    int t, i;
    scanf("%d", &t);

    for ( i = 0; i < t; i++) {
        char str[201];
        scanf(" %[^\n]", str);

        int wordCount = countWords(str);
        printf("%d\n", wordCount);
    }

    return 0;
}
