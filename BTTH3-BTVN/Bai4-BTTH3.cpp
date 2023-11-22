#include <stdio.h>

int main (){
	int N, i, count, sum;
	printf("Nhap vao so N:");
	scanf("%d", &N);
	for (i=1, count=0; count<N; i+=2, count++){
		sum += i;
	}
	printf("tong cua N so le dau tien la:%d", sum);
	return 0;
}
