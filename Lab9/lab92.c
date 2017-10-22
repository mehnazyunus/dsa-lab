//creating tree for infix expression
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	char data;
	struct node *left, *right;
}node;

struct node* stack1[100];
int top1 = -1;

char stack[100];
int top = -1;
char post[100];


//stack for expression tree
void push1(node* item) {
	stack1[++top1] = item;
}

node* pop1(){
	if(top1 == -1)
		return NULL;
	return stack1[top1--]; 
}

//for conversion of infix to postfix
void push(int data) {
  stack[++top] = data;
}

char pop() {
  if(top == -1)
    return '\0';
  return stack[top--];
}

int isOperand(char c) {
  return (c >= 'a' && c <='z')||(c >= 'A' && c <='Z');
}

void traverse() {
  int p = 0;
  while(p <= top){
    printf(" %c",stack[p]);
    p++;
  }
}

int prec(char op) {
  switch(op) {
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    case '^': return 3;
    default: return 0;
  }
}

void convert(char exp[100]) {
  int i, k;
  for(i = 0, k = -1; exp[i]; ++i){

    if(isOperand(exp[i]))
      post[++k] = exp[i];
    else if(exp[i] == '(')
      push(exp[i]);
    else if(exp[i] == ')') {
      while(stack[top] != '(' && top != -1)
        post[++k] = pop();
      top--; //remove ( from stack
    }
    else {
          while(prec(exp[i]) <= prec(stack[top])){
            post[++k] = pop();
          }
          push(exp[i]);
   }
 }
  while(top != -1)
    post[++k] = pop();
  post[++k] = '\0';
}




void inorder(node* root) {
	
	if(root != NULL) {
		inorder(root->left);
		printf("%c ", root->data);
		inorder(root->right);
	}
}


void main(){
	char inf[100];
	printf("\nEnter infix expression : ");
  	scanf("%s", inf);
  	convert(inf);
  	int i;
  	for(i = 0;post[i] != '\0'; ++i) {
  		
  		if(isOperand(post[i])){
  			node* op = (node*)malloc(sizeof(node));
  			op->data = post[i];
  			op->right = NULL;
  			op->left = NULL;
  			push1(op);
  		}
  		else {
  			node* op = (node*)malloc(sizeof(node));
  			op->data = post[i];
  			op->right = pop1();
  			op->left = pop1();
  			push1(op);	
  		}
  	}
  	
    printf("\nInorder traversal of expression tree : ");
  	inorder(stack1[top1]);

}