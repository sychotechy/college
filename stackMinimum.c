#include<stdio.h>
#include<stdbool.h>
int stack[50],minStack[50],top=-1,minTop=-1;
bool isEmpty(){
	if(top==-1){
		return true;
	}
	else{
		return false;
	}
}
void push(int element, int maxSize){
	if(top==maxSize-1){
		printf("\nStack is full\n");
	}
	else{
		stack[++top]=element;
		if(minTop==-1 || element<minStack[minTop]){
			minStack[++minTop]=element;
		}
	}
}
void pop(){
	if(top==-1){
		printf("Stack is empty\n");
	}
	else{
		if(stack[top]==minStack[minTop]){
			minStack[minTop--];
		}
		printf("Popped element : %d",stack[top--]);
	}
}
void peek(){
	if(isEmpty()){
		printf("Stack is empty\n");
	}
	else{
		printf("Top element is : %d",stack[top]);
	}
}
void display(){
	int i;
	if(isEmpty()){
		printf("Stack is empty\n");
	}
	else{
		for(i=top;i>=0;i--){
			printf("%d\n",stack[i]);
		}
	}
}
void findMin(){
	if(minTop==-1){
		printf("Stack is empty\n");
	}
	else{
		printf("Minimum element : %d",minStack[minTop]);
	}
}
int main(){
	int choice,maxSize,flag=1,element;
	printf("Enter the max size of stack : ");
	scanf("%d",&maxSize);
	do{
		printf("\n** Stack operations **\n");
		printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Minimum element\n6.Exit\nEnter your option : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter element to push : ");
				scanf("%d",&element);
				push(element,maxSize);
				break;
				
			case 2:
				pop();
				break;
				
			case 3:
				peek();
				break;
			
			case 4:
				display();
				break;
			
			case 5:
				findMin();
				break;
			
			case 6:
				flag=0;
				break;
			
			default:
				printf("\nWrong option\n");
				
		}
	}while(flag);
}