#include <stdio.h>


void addArr(int* arr, int size) {
    int i; 
	for ( i = 0; i < size; i++) {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }
}


void printArr(int* arr, int size) {
    int i;
	printf("\nMang vua nhap la: ");
    for ( i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int findArr(int* arr, int size, int x) {
    int i;
	for ( i = 0; i < size; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int size;
    printf("Nhap kich thuoc mang: ");
    scanf("%d", &size);

    int* arr = (int*)malloc(size * sizeof(int));

    addArr(arr, size);
    printArr(arr, size);

    int x;
    printf("\nNhap phan tu can tim: ");
    scanf("%d", &x);

    int index = findArr(arr, size, x);

    if (index != -1) {
        printf("\nPhan tu %d co trong mang tai vi tri %d", x, index+1);
    } else {
        printf("\nPhan tu %d khong co trong mang", x);
    }

    free(arr);

    return 0;
}
