#include<stdio.h>
void printArray(int numberArray[],int maxSize){
	int i;
	printf("\n***** Array Elements *****\n");
	for(i=0;i<maxSize;i++){
		printf("%d\t",numberArray[i]);
	}
	printf("\n");
}
void rotateArray(int numberArray[],int maxSize,int direction,int noOfRotation){
	int position=1,i;
	switch(direction){
		case 1:
			while(position<=noOfRotation){
				int lastElement = numberArray[0];
				for(i=0;i<maxSize-1;i++){
					numberArray[i] = numberArray[i+1];
				}
				numberArray[maxSize-1] = lastElement;
				position++;
			}
			break;
			
		case 2:
			while(position<=noOfRotation){
				int firstElement = numberArray[maxSize-1];
				for(i=maxSize-1;i>0;i--){
					numberArray[i] = numberArray[i-1];
				}
				numberArray[0] = firstElement;
				position++;
			}
			break;
			
		default:
			printf("\n***** Wrong option*****\n");
	}
		
}
int main(){
	int numberArray[50],maxSize,i,flag=1,userOption,direction,noOfRotation;
	printf("Enter size of the array : ");
	scanf("%d",&maxSize);
	printf("Enter %d elements : ",maxSize);
	for(i=0;i<maxSize;i++){
		scanf("%d",&numberArray[i]);
	}
	do{
		printf("**** Operations ****\n1.Rotate array\n2.Print array\n3.Exit\nEnter your option : ");
		scanf("%d",&userOption);
		switch(userOption){
			case 1:
				printf("Enter direction to rotate (1-Left, 2-Right) : ");
				scanf("%d",&direction);
				printf("Enter number of rotations : ");
				scanf("%d",&noOfRotation);
				rotateArray(numberArray,maxSize,direction,noOfRotation);
				break;
				
			case 2:
				printArray(numberArray,maxSize);
				break;
				
			case 3:
				flag=0;
				break;
				
			default:
				printf("\n***** Wrong option *****\n");
		}
	}while(flag);
}
