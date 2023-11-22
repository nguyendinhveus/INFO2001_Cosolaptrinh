#include <stdio.h>

int main (){
	int n;
	printf("nhap mot so nguyen:");
	scanf("%d", &n);
	if (n%2 == 0){
		printf("so %d la so chan", n);
	} else {
		printf("so %d la so le", n);
	}
	
	return 0;
} 
