#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
	}node;
struct node *head=NULL;
void reverse(){
	struct node *current=head, *prev=NULL,*next;
	while(current!=NULL){
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
}
void sort(){
	struct node *temp1=head,*temp2;
	int temp;
	for(temp1=head;temp1!=NULL;temp1=temp1->next){
		for(temp2=head;temp2->next!=NULL;temp2=temp2->next){
			if(temp2->data>temp2->next->data){
				temp=temp2->data;
				temp2->data=temp2->next->data;
				temp2->next->data=temp;
			}
		}
	}
}
void insert(int e){
	struct node* new=malloc(sizeof(node));
	if(new==NULL)
		printf("Memory insufficient\n");
	else{
		struct node* ptr=head;
		if(e<head->data){
			new->next=head;
			new->data=e;
			head=new;
		}
		else{
			while(ptr->next!=NULL){
				if(!((ptr->next->data)<e))
					break;
				ptr=ptr->next;
			}
			new->data=e;
			new->next=ptr->next;
			ptr->next=new;	
		}
	}
}
void dispList(){
	printf("\n");
	struct node* ptr;
	for(ptr=head;ptr!=NULL;ptr=ptr->next)
		printf("%d\t",ptr->data);
	printf("\n");
}
	
void main(){
	int n,e,o=0;
	head=malloc(sizeof(node));
	printf("Enter the number of elements in the linked list: ");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	scanf("%d",&head->data);
	for(int i=1;i<n;i++){
		scanf("%d",&e);
		insert(e);
	}
	while(o!=4){
		printf("The list is\n");
		dispList();
		printf("\n** Operations **\n1.Reverse the list\n2.Sort the list\n3.Insert new element\n4.Exit\nEnter option : ");
		scanf("%d",&o);
		switch(o){
			case 1:
				reverse();
				break;
			case 2:
				sort();
				break;
			case 3:
				printf("Enter the element:");
				scanf("%d",&e);
				insert(e);
				break;
			case 4:
				break;
			default:
				printf("Invalid input\n");
		}
	}
}
