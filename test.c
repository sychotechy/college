#include<stdio.h>
void sortArray(int numberArray[],int limit){
	int i,j,temp;
	for(i=0;i<limit-1;i++){
		for(j=i+1;j<limit;j++){
			if(numberArray[i]>numberArray[j]){
				temp = numberArray[i];
				numberArray[i] = numberArray[j];
				numberArray[j] = temp;
			}
		}
	}
}
int main(){
	int numberArray[20],limit,i,j,temp;
	printf("Enter size of array : ");
	scanf("%d",&limit);
	printf("Enter %d elements : ",limit);
	for(i=0;i<limit;i++){
		scanf("%d",&numberArray[i]);
	}
	sortArray(numberArray,limit);
	printf("Sorted array : ");
	for(i=0;i<limit;i++){
		printf("%d\t",numberArray[i]);
	}
	printf("\n");
}
