#include <stdio.h>

// H�m t?m USCLN s? d?ng thu?t to�n Euclid
int timUSCLN(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// H�m t?m BSCNN s? d?ng c�ng th?c BSCNN = (a * b) / USCLN(a, b)
int timBSCNN(int a, int b) {
    int uscln = timUSCLN(a, b);
    int bscnn = (a * b) / uscln;
    return bscnn;
}

int main() {
    int a, b;

    // Nh?p d? li?u t? ng�?i d�ng
  
    scanf("%d %d", &a, &b);

    // T?m USCLN v� BSCNN
    int uscln = timUSCLN(a, b);
    int bscnn = timBSCNN(a, b);

    // In k?t qu?
    printf("%d\n", uscln);
    printf("%d\n", bscnn);

    return 0;
}
