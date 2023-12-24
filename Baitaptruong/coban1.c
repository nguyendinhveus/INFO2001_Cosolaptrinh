#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    if (b != 0) {
	int sum = a + b;
    int difference = a - b;
    int product = a * b;
    float quotient = (float) a / b;
    int remainder = a % b;
    printf("%d %d %d %.2f %d\n", sum, difference, product, quotient, remainder);

   	}else{
   		printf("0"); 
	} 


   
    return 0;
}
