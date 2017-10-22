//implement binary tree using array - insertion, deletion, search
#include<stdio.h>
#include<stdlib.h>

int tree[100];
int n = 10;

void insert(int index, int item){
	if(tree[index] == 0)
		tree[index] = item;
	else {
		printf("\nInsert to L(0) or R(1) ?");
		int side;
		scanf("%d", &side);
		if(side == 0)
			insert(2*index + 1, item);
		else
			insert(2*index + 2, item);
	}
}

void traverse() {
	int i;
	for(i = 0; i < n; ++i)
		printf("| %d", tree[i]);
}

void delete(int index){
	if(tree[index] == 0)
		return;
	tree[index] = 0;
	delete(2*index + 1);
	delete(2*index + 2);
}

void main() {
	int i, k = 0;
	for(i = 0; i < n; ++i)
		tree[i] = 0;
	int ch;
	do {
		printf("\n1.Insert 2.Search 3.Traverse 4.Delete 5.Exit");
		scanf("%d", &ch);
		if(ch == 1) {
			if(k == 0) {
				printf("\nEnter root");
				scanf("%d", &tree[0]);	
				k++;
			}
			else {
				int data;
				printf("\n Enter data : ");
				scanf("%d", &data);
				insert(0, data);
				traverse();
			}
		}
		else if(ch == 2){
			int i, e, flag = 0;
			printf("\nEnter element to be searched : ");
			scanf("%d", &e);
			for(i = 0; i < n; ++i) {
				if(tree[i] == e){
					flag = 1;
					printf("\nELement found ");
					break;
				}
			}
			if(!flag)
				printf("\nELement not found");
		}
		else if(ch == 3)
			traverse();
		else if(ch == 4) {
			int e;
			printf("\nEnter element to be deleted : ");
			scanf("%d", &e);
			int i;
			for(i = 0; i < n; ++i) {
				if(tree[i] == e) {
					delete(i);
					break;
				}
			}
		}

	}while(ch != 5);
		
}