#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node node;
node *top = NULL;
void push(){
	node *newNode = (node*)malloc(sizeof(node));
	printf("Enter value to insert : ");
	scanf("%d",&newNode->data);
	if(top!=NULL){
		newNode->next = top;
	}
	top=newNode;
}
void pop(){
	if(top==NULL){
		printf("Stack is empty\n");
		return;
	}
	else{
		node *temp = top;
		top = top->next;
		printf("Popped element : %d\n",temp->data);
		free(temp);
	}
}
void peek(){
	if(top == NULL){
		printf("Stack is empty\n");
	}
	else{
		printf("Top element : %d\n",top->data);
	}
}
void display(){
	if(top == NULL){
		printf("Stack is empty\n");
		return;
	}
	node *ptr = top;
	while(ptr!=NULL){
		printf("%d\t",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}
int main(){
	int value,flag=1,option;
	do{
		printf("** Operations **\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\nEnter you option : ");
		scanf("%d",&option);
		switch(option){
			case 1:
				push();
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
				printf("Wrong option\n");
		}
	}while(flag);
}
