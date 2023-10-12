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
	int maxSizeOne,maxSizeTwo,i,length,power,start,end,middle;
	printf("Enter the number of terms of polynomial 1 : ");
	scanf("%d",&maxSizeOne);
	struct Polynomial polynomialOne[maxSizeOne];
	printf("Enter the terms of polynomial 1 : ");
	for(i=0;i<maxSizeOne;i++){
		printf("Coefficient : ");
		scanf("%d",&polynomialOne[i].coefficient);
		printf("Power : ");
		scanf("%d",&polynomialOne[i].power);
	}
	sortPolynomial(polynomialOne,maxSizeOne);
	printf("Enter the number of terms of polynomial 2 : ");
	scanf("%d",&maxSizeTwo);
	struct Polynomial polynomialTwo[maxSizeTwo];
	printf("Enter the terms of polynomial 2 : ");
	for(i=0;i<maxSizeTwo;i++){
		printf("Coefficient : ");
		scanf("%d",&polynomialTwo[i].coefficient);
		printf("Power : ");
		scanf("%d",&polynomialTwo[i].power);
	}
	sortPolynomial(polynomialTwo,maxSizeTwo);
	struct Polynomial resultPolynomial[maxSizeOne+maxSizeTwo];
	for(i=0;i<maxSizeOne;i++){
		resultPolynomial[i] = polynomialOne[i];
	}
	length = maxSizeOne;
	for(i=0;i<maxSizeTwo;i++){
		power = polynomialTwo[i].power;
		start = 0;
		end = maxSizeOne-1;
		while(start<=end){
			middle = (start+end)/2;
			if(resultPolynomial[middle].power == power) break;
			else if(resultPolynomial[middle].power > power){
				end = middle-1;
			}
            else start = middle+1;
        }
        if(resultPolynomial[middle].power == power){
        	resultPolynomial[middle].coefficient += polynomialTwo[i].coefficient;
        }
        else{
            resultPolynomial[length].coefficient = polynomialTwo[i].coefficient;
            resultPolynomial[length].power = polynomialTwo[i].power;
            length++;
        }
    }
    sortPolynomial(resultPolynomial,length);
    for(i=length-1;i>=0;i--){
    	if(resultPolynomial[i].power!=0){
    		printf("%dx^%d",resultPolynomial[i].coefficient,resultPolynomial[i].power);
    	}
    	else{
    		printf("%d",resultPolynomial[i].coefficient);
    	}
    	if(i!=0){
    		printf(" + ");
    	}
    }
}
