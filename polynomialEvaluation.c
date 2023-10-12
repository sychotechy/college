#include<stdio.h>
struct Polynomial{
	int coefficient;
	int power;
};
void sortPolynomial(struct Polynomial *polynomial, int maxSize){
	int i,j;
	struct Polynomial temp;
	for(i=0;i<maxSize-1;i++){
		for(j=i+1;j<maxSize;j++){
			if(polynomial[i].power>polynomial[j].power){
				temp = polynomial[i];
				polynomial[i] = polynomial[j];
				polynomial[j] = temp;
			}
		}
	}
}
int main(){
	int maxSize,sum=0,i,j,x;
	printf("Enter the no of terms of polynomial : ");
	scanf("%d",&maxSize);
	struct Polynomial polynomialOne[maxSize];
	printf("Enter the terms of polynomial : ");
	for(i=0;i<maxSize;i++){
		printf("Coefficient : ");
		scanf("%d",&polynomialOne[i].coefficient);
		printf("Power : ");
		scanf("%d",&polynomialOne[i].power);
	}
	sortPolynomial(polynomialOne,maxSize);
	printf("Enter value of x : ");
	scanf("%d",&x);
	for(i=0;i<maxSize;i++){
		int power = polynomialOne[i].power;
		int product = polynomialOne[i].coefficient;
		for(j=0;j<power;j++){
			product = product * x;
		}
		sum = sum + product;
	}
	printf("Value of polynomial for x = %d : %d \n",x,sum);
}
