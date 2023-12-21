#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node node;
node* createNode(int value){
	node *new = malloc(sizeof(node));
	new->left = NULL;
	new->right = NULL;
	new->data = value;
	return new;
}
node *insertLeft(node *root,int data){
	root->left = createNode(data);
	return root->left;
}
node *insertRight(node *root, int data){
	root->right = createNode(data);
	return root->right;
}
void inorder(node *root){
	if(root == NULL)
		return;
	inorder(root->left);
	printf("%d->",root->data);
	inorder(root->right);
}
void preorder(node *root){
	if(root == NULL)
		return;
	printf("%d->",root->data);
	preorder(root->left);
	preorder(root->right);
}
void postorder(node *root){
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d->",root->data);
}
int main(){
	int flag=1,option,element;
	node *root = NULL;
	do{
		printf("\n** Operations **\n1.Create Root\n2.Insert Left Child\n3.Insert Right Child\n4.Inorder\n5.Preorder\n6.Postorder\n7.Exit\nEnter option : ");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("Enter element : ");
				scanf("%d",&element);
				root = createNode(element);
				break;
			case 2:
				printf("Enter element : ");
				scanf("%d",&element);
				insertLeft(root,element);
				break;
			case 3:
				printf("Enter element : ");
				scanf("%d",&element);
				insertRight(root,element);
				break;
			case 4:
				inorder(root);
				break;
			case 5:
				preorder(root);
				break;
			case 6:
				postorder(root);
				break;
			case 7:
				flag=0;
				break;
			default:
				printf("\nWrong choice\n");
				break;
		}
	}while(flag);
}
