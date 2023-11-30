#include <stdio.h>


int binarySearch(int arr[], int left, int right, int x) {
    for (; left <= right;) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return mid; 
        }

        if (arr[mid] < x) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
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

    int result = binarySearch(arr, 0, n - 1, x);

    if (result == -1) {
        printf("Khong tim thay gia tri trong mang\n");
    } else {
        printf("Gia tri duoc tim thay tai vi tri so %d\n", result+1);
    }

    return 0;
}
