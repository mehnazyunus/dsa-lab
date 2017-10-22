//height of a given binary tree
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *right, *left;
}node;

void insert(node** root, int data) {
	if(*root == NULL) {
		*root = (node*)malloc(sizeof(node));
		(*root)->data = data;
		(*root)->right = NULL;
		(*root)->left = NULL;
	}
	else {
		printf("\nInsert to L(0) or R(1)?");
		int side;
		scanf("%d", &side);
		if(side == 0)
			insert(&(*root)->left, data);
		else 
			insert(&(*root)->right, data);	
	}
}

int height(node* root) {
	if(root == NULL)
		return 0;
	int l = height(root->left);
	int r = height(root->right);
	if(l >= r)
		return l+1;
	else
		return r+1;
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
			}
		}
	}while(ch == 1);
	printf("\nHeight : %d", height(root));
}