//inorder preorder postorder traversals
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *left, *right;
}node;

void insert(node** root, int item){
	if(!(*root)){
		*root = (node*)malloc(sizeof(node));
		(*root)->data = item;
		(*root)->right = NULL;
		(*root)->left = NULL;
	}
	else {
		printf("\nInsert to L(0) or R(1) ?");
		int side;
		scanf("%d", &side);
		if(side == 0)
			insert(&((*root)->left), item);
		else
			insert((&(*root)->right), item);
	}
}

void inorder(node* root) {
	
	if(root != NULL) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void preorder(node* root) {
	if(root != NULL) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node* root) {
	if(root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}

void main() {
	int i, k = 0;
	node *root = NULL;
	int ch;
	do {
		printf("\n1.Insert 2.Inorder 3.Preorder 4.Postorder 5.Exit");
		scanf("%d", &ch);
		if(ch == 1) {
			if(k == 0) {
				printf("\nEnter root");
				root = (node*)malloc(sizeof(node));
				root->right = NULL;
				root->left = NULL;
				scanf("%d", &root->data);	
				k++;
			}
			else {
				int data;
				printf("\n Enter data : ");
				scanf("%d", &data);
				insert(&root, data);
			}
		}
		else if(ch == 2) 
			inorder(root);
		else if(ch == 3) 
			preorder(root);
		else if(ch == 4) 
			postorder(root);

	}while(ch != 5);
	
		
}