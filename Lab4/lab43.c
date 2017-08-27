#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node {
  int data;
  struct node* xnp;
};

struct node* head = NULL;

struct node* XOR(struct node *a, struct node *b) {
  return (struct node*) ((unsigned int) (a) ^ (unsigned int) (b));
}

void insert(int pos, int data) {
  struct node* newptr = (struct node*)malloc(sizeof(struct node));
  newptr->data = data;
  //newptr->xnp = NULL;
  newptr->xnp = XOR(head, NULL);
  if(head == NULL){
    //newptr->xnp = XOR(head, NULL);
    printf("Checking null\n");
    head = newptr;
    return;
  }

  if(pos == 1){
    printf("Checking initial\n");
    //newptr->xnp = XOR(head, NULL);
    struct node* next = XOR(head->xnp, NULL);
    printf("1 done\n");
    head->xnp = XOR(next, newptr);
    printf("2 done\n");
    head = newptr;
    printf("3 done\n");
  }
}

void traverse() {
  struct node *cur = head, *prev = NULL, *next  ;
  printf("traverse\n" );
  while(cur != NULL){
    printf("inside\n");
    printf("%d-->", cur->data);
    printf("1 done\n");
    next = XOR(cur->xnp, prev);
    prev = cur;
    cur = next;
  }
  printf("NULL");
}

void delete(int pos){
  if(head == NULL)
    return;
  else if(pos == 1){
    struct node* throw = head;
    struct node* next = XOR(head->xnp, NULL);
    head = next;
    free(throw);
  }
}

void main() {
  int element;
  int ch, pos, data;
  char c;

do{
  printf( "\n1.Insert 2.Delete 3.Traverse");
  printf( "\nEnter choice : ");
  scanf("%d", &ch);
  if(ch == 1) {
    printf("\nEnter position and data : ");
    scanf("%d%d", &pos, &data );
    insert(pos, data);
    traverse();
  }
  else if(ch == 2) {
    printf("\nEnter position: ");
    scanf("%d", &pos);
    delete(pos);
    traverse();
  }
  else if(ch == 3)
    traverse();

  printf("\nContinue (y/n)");
  getchar();
  scanf("%c", &c);
}while(c == 'y');
}
