#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node node;
node *front = NULL;
node *rear = NULL;
void enQueue(){
	node *newNode = (node*)malloc(sizeof(node));
	printf("Enter data to insert : ");
	scanf("%d",&newNode->data);
	if(front == NULL){
		front = newNode;
	}
	else{
		rear->next = newNode;
	}
	rear = newNode;
}
void deQueue(){
	if(front == NULL){
		printf("Queue is empty\n");
		return;
	}
	node *temp = front;
	if(front == rear){
		rear = rear->next;
	}
	front = front->next;
	printf("Deleted element : %d\n",temp->data);
	free(temp);
}
void display(){
	node *ptr = front;
	while(ptr!=NULL){
		printf("%d\t",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}
int main(){
	int option,flag=1;
	do{
		printf("** Operations **\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter option : ");
		scanf("%d",&option);
		switch(option){
			case 1:
				enQueue();
				break;
			
			case 2:
				deQueue();
				break;
				
			case 3:
				display();
				break;
				
			case 4:
				flag=0;
				break;
			
			default:
				printf("Wrong option\n");		
		}
	}while(flag);
}
