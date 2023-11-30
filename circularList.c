#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
}node;
struct node *head = NULL;
void insertEnd(int element){
	if(head==NULL){
		head = malloc(sizeof(node));
		head->data = element;
		head->next = head;
		head->prev = head;
	}
	else{
		struct node *new = malloc(sizeof(node));
		new->data = element;
		new->prev = head->prev;
		head->prev->next = new;
		head->prev = new;
		new->next = head;
	}
}
void insertFront(int element){
	insertEnd(element);
	head = head->prev;
}
void insertPos(int element, int pos){
	if(pos==0){
		insertFront(element);
	}
	else{
		struct node* ptr = head;
		int currentPos = 0;
		do{
			ptr=ptr->next;
			currentPos++;
		}
		while(currentPos!=pos&&ptr!=head);
		if(currentPos==pos){
			struct node *new = malloc(sizeof(node));
			new->data = element;
			ptr->prev->next=new;
			new->next=ptr;
			new->prev=ptr->prev;
			ptr->prev=new;
		}
		else{
			printf("Location is out of range\n");
		}
	}
}
void displayList(){
	struct node* ptr = head;
	do{
		printf("%d \t",ptr->data);
		ptr=ptr->next;
	}while(ptr!=head);
	printf("\n");
}
void deleteEnd(){
	struct node *temp;
	if(head==NULL){
		printf("List is empty\n");
	}
	else{
		temp = head->prev;
		temp->prev->next = head;
		head->prev = temp->prev;
		free(temp);
	}
}
void deleteFront(){
	struct node *temp;
	if(head==NULL){
		printf("List is empty\n");
	}
	else{
		temp = head;
		head->next->prev = temp->prev;
		head->prev->next = temp->next;
		head = temp->next;
		free(temp);
	}
}
void deleteData(int element){
	struct node *temp,*ptr;
	if(head==NULL){
		printf("List is empty\n");
	}
	else{
		ptr = head;
		do{
			if(ptr->data==element){
				temp = ptr;
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				ptr = ptr->next;
				free(temp);
			}
			else{
				ptr = ptr->next;
			}
			
		}while(ptr!=head);
	}
}
void search(int element){
	if(head==NULL){
		printf("List is empty\n");
	}
	else{
		int flag=0,pos=0;
		struct node *ptr = head;
		do{
			if(ptr->data==element){
				printf("The element is find at location : %d\n",pos);
				flag=1;
			}
			pos++;
			ptr = ptr->next;
		}while(ptr!=head);
		if(flag==0){
			printf("Element not found\n");
		}
	}
}
int main(){
	int limit,element,option,flag=1,position;
	printf("Enter the number of elements of linkedlist : ");
	
	scanf("%d",&limit);
	printf("Enter the elements : ");
	for(int i=0;i<limit;i++){
		scanf("%d",&element);
		insertEnd(element);
	}
	do{
		printf("List : ");
		displayList();
		printf("\n** Operations **\n1.Insert at front\n2.Insert at end\n3.Insert at position\n4.Delete at front\n5.Delete at end\n6.Delete at position\n7.Delete given data\n8.Exit\nEnter option : ");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("Enter element : ");
				scanf("%d",&element);
				insertFront(element);
				break;
				
			case 2:
				printf("Enter element : ");
				scanf("%d",&element);
				insertEnd(element);
				break;
			
			case 3:
				printf("Enter element and position : ");
				scanf("%d %d",&element,&position);
				insertPos(element,position);
				break;
				
			case 4:
				deleteFront();
				break;
				
			case 5:
				deleteEnd();
				break;
				
			case 6:
				printf("Enter element : ");
				scanf("%d",&element);
				deleteData(element);
				break;
				
			case 7:
				printf("Enter element to search : ");
				scanf("%d",&element);
				search(element);
				break;
			
			case 8:
				flag=0;
				break;
				
			default:
				printf("Wrong option\n");
		
		}
	}while(flag);
}
