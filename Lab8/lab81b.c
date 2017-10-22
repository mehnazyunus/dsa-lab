//imprement binary tree using linked list - insertion, deletion, search
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *left, *right;
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

 int search(node* root, int e) {
 	if(root == NULL)
		return 0;
	if(root->data == e) 
		return 1;
	
	return search(root->right, e) || search(root->left, e);
}

void deleteSub(node* root) {
	if(root == NULL)
		return;
	deleteSub(root->left);
	deleteSub(root->right);
	free(root->left);
	free(root->right);
}

void delete(node* root, int e) {
	if(root == NULL)
		return;
	if(root->data == e) {
		deleteSub(root);
		//node* temp = root;
		free(root);
	}
}

void main() {
	int i, k = 0;
	node *root = NULL;
	int ch;
	do {
		printf("\n1.Insert 2.Search 3.Traverse 4.Deletion 5.Exit");
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
		else if(ch == 2){
			int i, e, flag = 0;
			printf("\nEnter element to be searched : ");
			scanf("%d", &e);
			flag = search(root, e);
			if(flag)
				printf("\nELement found");
			else
				printf("\nElement not found");
		}
		else if(ch == 3)
			inorder(root);
		else if(ch == 4) {
			int e;
			printf("\nEnter element to be deleted : ");
			scanf("%d", &e);
			delete(root, e);
			inorder(root);
		}



	}while(ch != 5);
		
}