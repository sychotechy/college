#include<stdio.h>
int search(int numberArray[20],int limit,int target){
	int i;
	for(i=0;i<limit;i++){
		if(numberArray[i]==target){
			return i;
		}
	}
	return -1;
}
int main(){
	int numberArray[20],limit,element,position,i;
	printf("Enter size of the array : ");
	scanf("%d",&limit);
	printf("Enter %d elements : ",limit);
	for(i=0;i<limit;i++){
		scanf("%d",&numberArray[i]);
	}
	printf("Enter element to search : ");
	scanf("%d",&element);
	position = search(numberArray,limit,element);
	if(position==-1){
		printf("Element not found\n");
	}
	else{
		printf("Element found at position : %d\n",position+1);
	}
}
