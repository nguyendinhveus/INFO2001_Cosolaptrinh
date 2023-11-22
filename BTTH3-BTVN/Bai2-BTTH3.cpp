#include <stdio.h>

int main(){
	float point;
	printf("Hay nhap dung diem cua hoc sinh theo thang diem 10:");
	scanf("%f", &point);
	if (9 <= point && point <= 10){
		printf("day la hoc sinh xuat sac");
	} else if (point >= 8){
		printf("day la hoc sinh gioi");
	} else if (point >= 6.5){
		printf("day la hoc sinh kha");
	} else if (point >= 5){
		printf("day la hoc sinh trung binh ");
	} else if (point >= 0){
		printf("day la hoc sinh yeu");
	}
	return 0;
}
