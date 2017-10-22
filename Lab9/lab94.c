//create mirror of given tree
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *right, *left;
}node;

void insert(node** root, int data) {
	if(*root == NULL) {
		*root = (node*)malloc((sizeof(node)));
		(*root)->data = data;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else {
		printf("\nInsert to L(0) or R(1) ?");
		int side;
		scanf("%d", &side);
		if(side == 0)
			insert(&((*root)->left), data);
		else
			insert((&(*root)->right), data);
	}
}

void inorder(node* root) {
	
	if(root != NULL) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

node* createnode(int data) {
	node* newnode = (node*)malloc((sizeof(node)));
	newnode->data = data;
	newnode->right = NULL;
	newnode->left = NULL;
	return newnode;
}

node* mirror(node* root){
	if(root == NULL)
		return NULL;
	node* tree = createnode(root->data);
	if(root->left == NULL && root->right == NULL)
		return tree;
	tree->left = mirror(root->right);
	tree->right = mirror(root->left);
	return tree;
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
				printf("\n Enter data : ");
				scanf("%d", &data);
				insert(&root, data);
			}
		}
	}while(ch == 1);
	node* tree = mirror(root);
	inorder(tree);
}