#include<stdio.h>
int main(){
	int numberArray[20],limit,i,j,temp;
	printf("Enter size of array : ");
	scanf("%d",&limit);
	printf("Enter %d elements : ",limit);
	for(i=0;i<limit;i++){
		scanf("%d",&numberArray[i]);
	}
	for(i=0;i<limit-1;i++){
		for(j=i+1;j<limit;j++){
			if(numberArray[i]>numberArray[j]){
				temp = numberArray[i];
				numberArray[i] = numberArray[j];
				numberArray[j] = temp;
			}
		}
	}
	printf("Sorted array : ");
	for(i=0;i<limit;i++){
		printf("%d\t",numberArray[i]);
	}
	printf("\n");
}
