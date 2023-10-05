#include<stdio.h>
void printArray(int numberArray[],int limit){
	int i;
	printf("Array elements : ");
	for(i=0;i<limit;i++){
		printf("%d\t",numberArray[i]);
	}
}
void rotateArray(int numberArray[],int limit,int direction,int noOfRotation){
	if(direction==1){
		
	}
}
int main(){
	int numberArray[20],limit,i,selectedOption,flag=1,noOfRotation,direction;
	printf("Enter the size of array : ");
	scanf("%d",&limit);
	printf("Enter %d elements : ");
	for(i=0;i<limit;i++){
		scanf("%d",&numberArray[i]);
	}
	do{
		printf("\n***** Select Operation *****\n1.Rotate Array\n2.Print Array\n3.Exit\nEnter option : ");
		scanf("%d",&selectedOption);
		switch(selectedOption){
			case 1:
				printf("Enter number of rotation : ");
				scanf("%d",&noOfRotation);
				printf("Enter direction of rotation (1.Left 2.Right) : ");
				scanf("%d",&direction);
				rotateArray(numberArray,limit,direction,noOfRotation);
				break;
				
			case 2:
				printArray(numberArray,limit);
				break;

			case 3:
				flag=0;
				break;

			default:
				printf("\n**** Wrong option ****\n");
		}
	}while(flag);
}
