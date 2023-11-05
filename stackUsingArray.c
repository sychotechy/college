#include<stdio.h>
#include<stdbool.h>
int stack[50],top=-1;
bool isEmpty(){
	if(top==-1){
		return true;
	}
	else{
		return false;
	}
}
void push(int element,int maxSize){
	if(top==maxSize-1){
		printf("Stack is full\n");
	}
	else{
		stack[++top]=element;
	}
}
void pop(){
	if(isEmpty()){
		printf("Stack is empty\n");
	}
	else{
		printf("Popped element : %d",stack[top--]);
	}
}
void peek(){
	if(isEmpty()){
		printf("Stack is empty\n");
	}
	else{
		printf("Top element : %d",stack[top]);
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
int main(){
	int choice,maxSize,flag=1,element;
	printf("Enter max size of stack : ");
	scanf("%d",&maxSize);
	do{
		printf("\n** Stack operations **\n");
		printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\nEnter your option : ");
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
				flag=0;
				break;
			
			default:
				printf("\n*** Wrong choice ***\n");
		}
	}while(flag);
}