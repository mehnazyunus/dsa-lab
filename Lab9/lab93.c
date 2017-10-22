//given inorder and preorder traversal, construct the binary tree
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *right, *left;
}node;

int search(int a[], int key, int start, int end) {
	int i;
	for(i = start; i <= end; ++i)
		if(a[i] == key)
			return i;
}

node* createNode(int data) {
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->right = NULL;
	newnode->left = NULL;
	return newnode;
}

node* makeTree(int in[], int pre[], int start, int end){
	static int preIndex = 0;
	if(start > end)
		return NULL;
	node* Node = createNode(pre[preIndex++]);
	if(start == end) // leaf node
		return Node;

	int inIndex = search(in, pre[preIndex-1], start, end);
	
	Node->left = makeTree(in, pre, start, inIndex - 1);
	Node->right = makeTree(in, pre, inIndex+1, end);
	return Node;
}

void postorder(node* root) {
	if(root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
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

void main() {
	int in[100], pre[100], i;
	int nodes;
	printf("\nEnter the no of nodes: ");
	scanf("%d", &nodes);
	printf("\nEnter inorder traversal: ");
	for(i = 0; i < nodes; ++i)
		scanf("%d", in+i);
	printf("Enter preorder traversal: ");
	for(i = 0; i < nodes; ++i)
		scanf("%d", pre+i);
	node* tree = makeTree(in, pre, 0, nodes-1);
	printf("\nPostorder : ");
	postorder(tree);
	printf("\nInorder : ");
	inorder(tree);
	printf("\nPreorder : ");
	preorder(tree);
}