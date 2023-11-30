#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main(){
    int arr[] = {6, 3, 5, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;
    printf("Mang ban dau: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    selectionSort(arr, n);
    printf("\nMang sau khi sap xep bang Selection Sort: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
//thoi gian trung binh sap xep lai day nay bang Selection Sort la 0,04715s  
