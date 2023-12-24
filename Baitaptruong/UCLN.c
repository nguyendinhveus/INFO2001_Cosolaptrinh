#include <stdio.h>


int timUSCLN(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int numTests;
    scanf("%d", &numTests);

    for (int i = 0; i < numTests; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        int uscln = timUSCLN(a, b);

        printf("%d\n", uscln);
    }

    return 0;
}
