#include<stdio.h>
#include<stdlib.h>
struct node{
	int coeff;
	int exp;
	struct node *next;
};
typedef struct node node;
void readPolynomial(node **poly,int coeff, int exp){
	node* temp = (node*)malloc(sizeof(node));
	temp->coeff = coeff;
	temp->exp = exp;
	temp->next = NULL;
	if(*poly==NULL){
		*poly=temp;
		return;
	}
	node *ptr = *poly;
	while (ptr->next != NULL) {
        ptr=ptr->next;
    }
    ptr->next = temp;
}
void displayPoly(node *poly){
	if (poly == NULL) {
        printf("0\n");
        return;
    }
    node* ptr = poly;
    while (ptr != NULL) {
        printf("%dx^%d", ptr->coeff, ptr->exp);
        if(ptr->next != NULL) {
            printf(" + ");
        }
        ptr = ptr->next;
    }
    printf("\n");
}
node* addPolynomials(node* poly1, node* poly2) {
    node* result = NULL;
    while(poly1 != NULL && poly2 != NULL) {
        if (poly1->exp == poly2->exp) {
            readPolynomial(&result, poly1->coeff+ poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exp > poly2->exp) {
            readPolynomial(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else {
            readPolynomial(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        readPolynomial(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        readPolynomial(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }
    return result;
}
int main(){
	node* poly1 = NULL;
    readPolynomial(&poly1, 5, 4);
    readPolynomial(&poly1, 3, 2);
    readPolynomial(&poly1, 1, 0);

    node* poly2 = NULL;
    readPolynomial(&poly2, 4, 4);
    readPolynomial(&poly2, 2, 2);
    readPolynomial(&poly2, 1, 1);

    printf("First polynomial: ");
    displayPoly(poly1);

    printf("Second polynomial: ");
    displayPoly(poly2);

    node* result = addPolynomials(poly1, poly2);
    printf("Result: ");
    displayPoly(result);
    return 0;
}
