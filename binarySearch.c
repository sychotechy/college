#include<stdio.h>
int search(int numberArray[20],int beginning,int ending,int target){
	int middle;
	while(beginning<=ending){
		middle = (beginning+ending)/2;
		if(numberArray[middle]==target){
			return middle;
		}
		else if(numberArray[middle]<target){
			beginning = middle+1;
		}
		else{
			ending = middle-1;
		}
	}
	return -1;
}
int main(){
	int numberArray[20],limit,position,element,i;
	printf("Enter number of array elements : ");
	scanf("%d",&limit);
	printf("Enter %d elements (Ascending order) : ",limit);
	for(i=0;i<limit;i++){
		scanf("%d",&numberArray[i]);
	}
	printf("Enter element to search : ");
	scanf("%d",&element);
	position = search(numberArray,0,limit-1,element);
	if(position==-1){
		printf("Element not found\n");
	}
	else{
		printf("Element found at position : %d\n",position+1);
	}
}
