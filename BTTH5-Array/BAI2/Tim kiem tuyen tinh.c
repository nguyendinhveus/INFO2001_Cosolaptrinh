#include <stdio.h>


int linearSearch(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int arr[] = {2, 5, 7, 10, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;

    printf("Nhap gia tri can tim x la : ");
    scanf("%d", &x);

    int result = linearSearch(arr, n, x);

    if (result == -1) {
        printf("Khong tim thay gia tri trong mang\n");
    } else {
        printf("Gia tri duoc tim thay tai vi tri so %d\n", result+1);
    }

    return 0;
}
