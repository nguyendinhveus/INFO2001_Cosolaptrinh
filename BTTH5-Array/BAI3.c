#include <stdio.h>
#define MAX_STUDENTS 50 
//gan gia tri co dinh so sinh vien nhieu nhat cua mot lop

//tinh diem trung binh  
float calculateAverage(float arr[], int n) {
    float sum = 0;
    int i;
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum/n;
}

int main() {
    int n;
    float scores[MAX_STUDENTS];
    int i;
    printf("nhap so luong sinh vien: ");
    scanf("%d", &n);

    if ( n > MAX_STUDENTS) {
        printf("so luong sinh vien vuot qua gioi han\n");
        return 0;
    }

    printf("nhap diem cua cac sinh vien:\n");
    for (i = 0; i < n; i++) {  
		printf("diem cua sinh vien %d: ", i + 1);
        scanf("%f", &scores[i]);        
    }
    float average = calculateAverage(scores, n);

    printf("diem trung binh cua lop la: %.2f ", average);

    return 0;
}
