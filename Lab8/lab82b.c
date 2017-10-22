//check whether tree is complete

#include<stdio.h>
#include<stdlib.h>

int tree[100];
int n = 10, k = 0;

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

int complete(int index) {
	if(tree[index] == 0)
		return 1;
	if(index >= k)
		return 0;
	return complete(2*index + 1) && complete(2*index+2);

}

void main() {
	int i;
	for(i = 0; i < n; ++i)
		tree[i] = 0;
	int ch;
	do {
		printf("\n1.Insert 2.Traverse 3.Exit");
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
				k++;			
			}
		}
		
	}while(ch != 3);
	if(complete(0))
		printf("\nTree is complete ");
	else
		printf("\nTree is not complete");		
}