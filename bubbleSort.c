#include<stdio.h>
int main(){
	int numberArray[20],limit,temp,i,j;
	printf("Enter number of array elements : ");
	scanf("%d",&limit);
	printf("Enter %d elements : ",limit);
	for(i=0;i<limit;i++){
		scanf("%d",&numberArray[i]);
	}
	for(i=0;i<limit;i++){
		for(j=0;j<limit-i-1;j++){
			if(numberArray[j]>numberArray[j+1]){
				temp = numberArray[j];
				numberArray[j] = numberArray[j+1];
				numberArray[j+1] = temp;
			}
		}
	}
	printf("Sorted array : ");
	for(i=0;i<limit;i++){
		printf("%d\t",numberArray[i]);
	}
	printf("\n");
}
