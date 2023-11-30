#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
}node;
struct node *frontIR=NULL, *rearIR=NULL, *frontOR=NULL, *rearOR=NULL;
void enqueueIR(int item){
	struct node* new=malloc(sizeof(node));
	new->data=item;
	new->next=NULL;
	if(frontIR==NULL)
		frontIR=rearIR=new;
	else{
		rearIR->next=new;
		rearIR=new;
	}
}
void dequeueIR(int end){
	if(frontIR==NULL)
		printf("Empty queue\n");
	else{ 
		if(end==1){
			printf("The deleted element is %d\n",frontIR->data);
			struct node *ptr=frontIR;
			frontIR=frontIR->next;
			if(frontIR==NULL)
				rearIR=NULL;
		}
		else if(end==2){
			struct node* temp;
			printf("The deleted element is %d\n",rearIR->data);	
			if(frontIR->next==NULL){
				temp=frontIR;
				free(temp);
				frontIR=rearIR=NULL;
			}
			else{
				struct node *ptr=frontIR;
				temp=rearIR;
				while(ptr->next!=rearIR)
					ptr=ptr->next;
				rearIR=ptr;
				rearIR->next=NULL;
				free(temp);
				
			}
		}
		else
			printf("Invalid input\n");
	}
}
void enqueueOR(int item,int end){
	if(end==1){
		struct node *new=malloc(sizeof(node));
		new->data=item;
		new->next=frontOR;
		frontOR=new;
		if(rearOR==NULL)
			rearOR=new;
	}
	else if(end==2){
		struct node *new=malloc(sizeof(node));
		new->data=item;
		new->next=NULL;
		rearOR->next=new;
		if(frontOR==NULL)
			frontOR=new;
	}
	else
		printf("Invalid input");
}	
void dequeueOR(){
	if(frontOR==NULL)
		printf("Empty queue\n");
	else{
		printf("%d",frontOR->data);
		struct node *ptr=frontOR;
		frontOR=frontOR->next;
		free(ptr);
		if(frontOR==NULL)
			rearOR=NULL;
	}
}
void dispQueue(struct node* front){
	if(front==NULL)
		printf("Empty queue\n");
	else{
		struct node* ptr=front;
		while(ptr!=NULL){
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
		printf("\n");
	}
}
void main(){
	int e,q,o=0;
	while(o!=5){
		printf("The input restricted queue is: ");
		dispQueue(frontIR);
		printf("The output restricted queue is: ");
		dispQueue(frontOR);
		printf("\nMENU\n1.Enqueue IR\t2.Dequeue IR\t3.Enqueue OR\t4.Dequeue OR\t5.Exit\n");
		scanf("%d",&o);
		switch(o){
			case 1:
				printf("Enter the element to be queued: ");
				scanf("%d",&e);
				enqueueIR(e);
				break;
			case 2:
				printf("Enter the end to be dequeued(1/2): ");
				scanf("%d",&q);
				dequeueIR(q);
				break;
			case 3:
				printf("Enter the element to be queued and the end(1/2): ");
				scanf("%d %d",&e,&q);
				enqueueOR(e,q);
				break;
			case 4:
				dequeueOR();
				break;
			case 5:
				printf("Exiting...\n");
				break;
			default:
				printf("Invalid input\n");
		}
		
	}
}		
