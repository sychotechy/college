#include<stdio.h>
#include<stdlib.h>
struct term{
	int coeff;
	int expo;
	struct term* next;
}term;
struct term *poly1=NULL, *poly2=NULL, *poly=NULL;
struct term* readPoly(struct term* p){
	int n,e,c;
	struct term *ptr = malloc(sizeof(term)),*head;
	head=ptr;
	printf("Enter the number of terms : ");
	scanf("%d",&n);
	printf("Enter the coefficient and exponent of each term : \n");
	for(int i=0;i<n;i++){
		scanf("%d %d",&c,&e);
		ptr->coeff=c;
		ptr->expo=e;
		if(i!=n-1){
			ptr->next=malloc(sizeof(term));
			ptr=ptr->next;
		}
		else{
			ptr->next=NULL;
		}
	}
	return head;
}
void dispPoly(struct term *p){
	struct term *ptr = p;
	while(ptr!=NULL){
		if(ptr->expo!=0){
			printf("%dx^%d",ptr->coeff,ptr->expo);
		}
		else{
			printf("%d",ptr->coeff);
		}
		if(ptr->next!=NULL){
			printf("+");
		}
		ptr=ptr->next;
	}
	printf("\n");
}
void polySum(struct term *poly1, struct term *poly2){
	struct term *ptr1=poly1, *ptr2=poly2, *ptr=malloc(sizeof(term)),*ptrr;
	poly=ptr;
	while(ptr1!=NULL && ptr2!=NULL){
		if(ptr1->expo>ptr2->expo){
			ptr->coeff=ptr1->coeff;
			ptr->expo=ptr1->expo;
			ptr1=ptr1->next;
		}
		else if(ptr1->expo<ptr2->expo){
			ptr->coeff=ptr2->coeff;
			ptr->expo=ptr2->expo;
			ptr2=ptr2->next;
		}
		else{
			if(ptr1->coeff+ptr2->coeff!=0){
				ptr->coeff=ptr1->coeff+ptr2->coeff;
				ptr->expo=ptr1->expo;
				ptr1=ptr1->next;
				ptr2=ptr2->next;
			}
			else{
				ptr1=ptr1->next;
				ptr2=ptr2->next;
			}
		}
		ptr->next=malloc(sizeof(term));
		ptr=ptr->next;
	}
	if(ptr!=NULL){
		ptrr=ptr1;
	}
	else{
		ptrr=ptr2;
	}
	while(ptrr!=NULL){
		ptr->coeff=ptrr->coeff;
		ptr->expo=ptrr->expo;
		if(ptrr->next!=NULL){
			ptr->next=malloc(sizeof(term));
			ptr=ptr->next;
		}
		else{
			ptr->next=NULL;
		}
		ptrr=ptrr->next;
	}
}
int main(){
	printf("Polynomial 1 : \n");
	poly1 = readPoly(poly1);
	dispPoly(poly1);
	printf("Polynomial 2 : \n");
	poly2 = readPoly(poly2);
	dispPoly(poly2);
	polySum(poly1,poly2);
	printf("Sum : ");
	dispPoly(poly);
}
