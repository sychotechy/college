#include<stdio.h>
#include<stdlib.h>
struct node{
	char data;
	struct node* next;
	struct node* prev;
}node;
struct node* head=NULL;
void insert(char c){
	if(head==NULL){
		head=malloc(sizeof(node));
		head->data=c;
		head->next=head;
		head->prev=head;
	}
	else{
		struct node *new=malloc(sizeof(node));
		new->data=c;
		new->prev=head->prev;
		head->prev->next=new;
		head->prev=new;
		new->next=head;
	}
}
void stringToDLL(char str[]){
	for(int i=0;str[i]!='\0';i++)
		insert(str[i]);
}
void isPalindrome(){
	struct node *front=head,*rear=head->prev;
	int flag=0;
	do{
		if((front->data)!=(rear->data)){
			flag=1;
			break;
		}
		front=front->next;
		rear=rear->prev;
	}while(front!=rear&&front->prev!=rear);
	if(flag==0)
		printf("It is a palindrome\n");
	else
		printf("It is not a palindrome\n");
}
void dispList(){
	struct node* ptr=head;
	do{
		printf("%c",ptr->data);
		ptr=ptr->next;
	}while(ptr!=head);
	printf("\n");
}
void main(){
	char str[100];
	printf("Enter the string: ");
	scanf("%s",str);
	stringToDLL(str);
	isPalindrome();
}
