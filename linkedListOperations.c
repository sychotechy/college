#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
	}node;
struct node *head=NULL;
void dispList(){
	printf("\n");
	struct node* ptr;
	for(ptr=head;ptr!=NULL;ptr=ptr->next)
		printf("%d\t",ptr->data);
	printf("\n");
}
void insertE(struct node* head, int e){
	struct node* new=malloc(sizeof(node));
	if(new==NULL)
		printf("Memory insufficient\n");
	else{
		struct node* ptr=head;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		new->data=e;
		ptr->next=new;
	}
}
void insertAfter(struct node* head,int e, int item){
	struct node* new=malloc(sizeof(node));
	if(new==NULL)
		printf("Memory insufficient\n");
	else{
		struct node* ptr=head;
		while(ptr->data!=item&&ptr!=NULL)
			ptr=ptr->next;
		if(ptr!=NULL){
			new->data=e;
			new->next=ptr->next;
			ptr->next=new;
		}
		else
			printf("Item not found\n");
	}
}
void insertBefore(int e, int item){
	struct node* new=malloc(sizeof(node));
	if(new==NULL)
		printf("Memory insufficient\n");
	else{
		struct node* ptr,*prev;
		for(ptr=head;ptr->data!=item&&ptr!=NULL;ptr=ptr->next)
			prev=ptr;
		if(ptr==head){
			new->next=head;
			new->data=e;
			head=new;
		}
		else if(ptr!=NULL){
			new->next=ptr;
			new->data=e;
			prev->next=new;
		}
		else
			printf("Item not found\n");
	}
}
void insertPos(int e, int p){
	struct node* new=malloc(sizeof(node));
	if(new==NULL)
		printf("Memory insufficient\n");
	else{
		struct node* ptr=head;
		int currentpos=0;
		if(p==0){
			new->next=head;
			new->data=e;
			head=new;
		}
		else{
			for(ptr=head;currentpos!=(p-1)&&ptr!=NULL;ptr=ptr->next)
				currentpos++;
			if(currentpos==p-1){
				new->data=e;
				new->next=ptr->next;
				ptr->next=new;
			}
			else
				printf("Location out of range");
		}
	}
}
void delData(int item){
	struct node *ptr=head,*prev,*temp;
	int flag=0;
	while(ptr!=NULL){
		if(ptr->data!=item){
			prev=ptr;
			ptr=ptr->next;
		}
		else{
			if(ptr==head){
				temp=ptr;
				ptr=ptr->next;
				head=head->next;
				free(temp);
			}
			else{
				temp=ptr;
				prev->next=ptr->next;
				ptr=ptr->next;
				free(temp);
				flag=1;
			}
			
		}
	}
	if(flag==0)
		printf("Item not found\n");
}
void delPos(int pos){
	struct node *ptr=head,*temp;
	int flag=0,currentpos=0;
	if(pos==0){
		temp=head;
		head=head->next;
		free(temp);
	}
	else{
		while(ptr!=NULL){
			if(currentpos==pos){
				temp->next=ptr->next;
				free(ptr);
				flag=1;
				break;
			}
			else{
				temp=ptr;
				ptr=ptr->next;
				currentpos++;
			}
		}
	}
	if(flag==0)
		printf("Location out of range\n");
}
void delSmallest(){
	struct node *ptr=head,*min=head,*prevmin,*temp;
	while(ptr!=NULL){
		if(ptr->data<min->data){
			prevmin=temp;
			min=ptr;
		}
		temp=ptr;
		ptr=ptr->next;
	}
	if(min==head){
		head=head->next;
		free(min);
	}
	else{
		prevmin->next=min->next;
		free(min);
	}
}
int search(struct node *head, int item){
	struct node *ptr;
	int currentpos=0;
	for(ptr=head;ptr!=NULL;ptr=ptr->next,currentpos++){
		if(ptr->data==item)
			return currentpos;
	}
	return -1;
}
	
void main(){
	int n,e,o=0,item,p;
	head=malloc(sizeof(node));
	printf("Enter the number of elements in the linked list: ");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	scanf("%d",&head->data);
	for(int i=1;i<n;i++){
		scanf("%d",&e);
		insertE(head,e);
	}
	while(o!=9){
		printf("The list is\n");
		dispList();
		printf("\n** Operations **\n1.Insert at the end\n2.Insert after an item\n3.Insert Before an item\n4.Insert at a position\n5.Delete given data\n6.Delete From Position\n7.Delete smallest element\n8.Search\n9.Exit\nEnter option : ");
		scanf("%d",&o);
		switch(o){
			case 1:
				printf("Enter the element: ");
				scanf("%d",&e);
				insertE(head,e);
				break;
			case 2:
				printf("Enter the element and the item:");
				scanf("%d %d",&e,&item);
				insertAfter(head,e,item);
				break;
			case 3:
				printf("Enter the element and the item:");
				scanf("%d %d",&e,&item);
				insertBefore(e,item);
				break;
			case 4:
				printf("Enter the element and the position:");
				scanf("%d %d",&e,&p);
				insertPos(e,p);
				break;
			case 5:
				printf("Enter the element: ");
				scanf("%d",&item);
				delData(item);
				break;
			case 6:
				printf("Enter the position: ");
				scanf("%d",&p);
				delPos(p);
				break;
			
			case 7:
				delSmallest();
				break;
			case 8:
				printf("Enter the element to be searched: ");
				scanf("%d",&item);
				p=search(head,item);
				if(p==-1)
					printf("Element not found\n");
				else
					printf("Element found at position %d\n",p);
				break;
			case 9:
				break;
			default:
				printf("Invalid input\n");
		}
	}
}
