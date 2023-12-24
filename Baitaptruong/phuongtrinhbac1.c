#include <stdio.h>

int main() {
    float a, b;
    scanf("%f %f", &a, &b);

    if (a == 0) {
        if (b == 0) {
            printf("Vo so nghiem\n");
        } else {
            printf("Vo nghiem\n");
        }
    } else {
        float x = -b / a;
        printf("%.2f\n", x);
    }

    return 0;
}
