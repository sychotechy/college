#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
}node;
struct node *front=NULL, *rear=NULL, *top=NULL;
void enqueue(int e){
	struct node* new=malloc(sizeof(node));
	new->data=e;
	new->next=NULL;
	if(front==NULL)
		front=rear=new;
	else{
		rear->next=new;
		rear=rear->next;
	}
}
int dequeue(){
	if(front==NULL)
		return -1;
	else{
		int item=front->data;
		struct node *ptr=front;
		if(front->next==NULL)
			front=rear=NULL;
		else
			front=front->next;
		free(ptr);
		return item;
	}
	
}
void push(int e){
	struct node *new=malloc(sizeof(node));
	if(new==NULL)
		printf("Insufficient memory\n");
	else{
		new->data=e;
		new->next=top;
		top=new;
	}
}
int pop(){
	struct node* ptr=top;
	if(ptr==NULL)
		return -1;
	else{
		int item=ptr->data;
		top=top->next;
		free(ptr);
		return item;
	}
}
void reverse(){
	while(front!=NULL)
		push(dequeue());
	while(top!=NULL)
		enqueue(pop());
}
void dispQueue(){
	if(front==NULL)
		printf("The queue is: Empty queue");
	else{
		printf("The queue is:\n");
		struct node* ptr=front;
		while(ptr!=NULL){
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
	}
}
void main(){
	int e,o=0,d;
	while(o!=4){
		dispQueue();
		printf("\nMENU\n1.Enqueue\t2.Dequeue\t3.Reverse the queue\t4.Exit\n");
		scanf("%d",&o);
		switch(o){
			case 1:
				printf("Enter the element to be queued: ");
				scanf("%d",&e);
				enqueue(e);
				break;
			case 2:
				d=dequeue();
				if(d==-1)
					printf("Empty queue cannot dequeue\n");
				else
					printf("The deleted element is %d\n",d);
				break;
			case 3:
				reverse();			
			case 4:
				printf("Exiting...\n");
				break;
			default:
				printf("Invalid input\n");
		}
		
	}
}
