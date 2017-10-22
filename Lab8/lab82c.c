//check if a binary tree is full
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *right, *left;
}node;

void insert(node** root, int item){
	if((*root) == NULL){
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
			insert(&(*root)->left, item);
		else
			insert(&(*root)->right, item);
	}
}

void inorder(node* root) {
	if(root != NULL) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

int isFull(node* root){
	if(root == NULL)//empty tree
		return 1;
	if(root->right == NULL && root->left == NULL)//no children
		return 1;
	if(root->right != NULL && root->left != NULL)//two children
		return 1;
	if(root->right != NULL || root->left != NULL)
		return 0;
	return (isFull(root->right) && isFull(root->left));
}

void main() {
	int i, k = 0;
	node *root = NULL;
	int ch;
	do {
		printf("\n1.Insert 2.Exit");
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
				printf("Enter data : ");
				scanf("%d", &data);
				insert(&root, data);
				inorder(root);
			}
		}
	}while(ch == 1);
	if(isFull(root))
		printf("\nFull");
	else
		printf("\nNot full");
}