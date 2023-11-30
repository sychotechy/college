#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *prev;
	struct node *next;
};
typedef struct node nd;
nd *front = NULL;
nd *rear = NULL;
int data;
nd *createNode(int data){
	nd *newNode = (nd *)malloc(sizeof(nd));
	newNode->data = data;
	return newNode;
}
void addFront(){
	printf("Enter the data of the new node : ");
	scanf("%d",&data);
	nd *newNode = createNode(data);
	if(front==NULL){
		front = rear = newNode;
		return;
	}
	newNode->next = front;
	front->prev = newNode;
	front = newNode;
}
void addBack(){
	printf("Enter the data of the new node : ");
	scanf("%d",&data);
	nd *newNode = createNode(data);
	if(front==NULL){
		front = rear = newNode;
		return;
	}
	rear->next = newNode;
	newNode->prev = rear;
	rear = newNode;
}
void removeFront(){
	if(front==NULL){
		printf("Queue is empty\n");
		return;
	}
	nd *temp = front;
	if(front==rear){
		front = front->next;
		rear = rear->next;
	}
	else{
		front = front->next;
		front->prev = NULL;
	}
	printf("The removed data : %d\n",temp->data);
	free(temp);
}
void removeBack(){
	if(front==NULL){
		printf("Queue is empty\n");
		return;
	}
	nd *temp = rear;
	if(front==rear){
		front = front->next;
		rear = rear->next;
	}
	else{
		rear = rear->prev;
		rear->next = NULL;
	}
	printf("The removed data : %d\n",temp->data);
	free(temp);
}
void display(){
	nd *ptr = front;
	printf("\n");
	while(ptr!=NULL){
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}
int main(){
	int option,flag=1;
	do{
		if(front!=NULL){
			display();
		}
		printf("\n** Operations **\n1.Add at front\n2.Add at back\n3.Remove at front\n4.Remove at back\n5.Exit\nEnter option : ");
		scanf("%d",&option);
		switch(option){
			case 1:
				addFront();
				break;
			
			case 2:
				addBack();
				break;
				
			case 3:
				removeFront();
				break;
			
			case 4:
				removeBack();
				break;
			
			case 5:
				flag=0;
				break;
			
			default:
				printf("Wrong option\n");	
		}
	}while(flag);
}
