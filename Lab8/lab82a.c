//check whether binary tree is perfect
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *right, *left;
}node;


int depth(node* root) {
	int d = 0;
	while(root != NULL){
		d++;
		root = root->left;
	}
	return d;
}

int isPerfect(node* root, int d, int level){
	if(root == NULL)//empty tree
		return 1;
	if(root->left == NULL && root->right == NULL)//leaf node
		return (d == level);
	if(root->left == NULL || root->right == NULL)//only one child
		return 0;
	return isPerfect(root->left, d, level+1)&&isPerfect(root->right, d, level+1);
}

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
	if(root!=NULL) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void main() {
	int i, k = 0;
	node *root = NULL;
	int ch;
	do {
		printf("\n1.Insert 4.Exit");
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
				inorder(root);
			}
		}
	}while(ch != 4);
	if(isPerfect(root, depth(root), 1))
		printf("\nPerfect");
	else
		printf("\nNot perfect");
}
