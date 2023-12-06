#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Nhap kich thuoc mang: ");
    scanf("%d", &size);

    
    int* arr = (int*) malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Khong the cap phat bo nho dong\n");
        exit(1);
    }


    printf("Nhap cac phan tu cua mang:\n");
    int i; 
	for ( i = 0; i < size; i++) {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }


    printf("\nMang vua nhap la: ");
    for ( i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}
