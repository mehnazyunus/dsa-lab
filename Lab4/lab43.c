#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node {
  int data;
  struct node* xnp;
};

struct node* head = NULL;

struct node* XOR(struct node *a, struct node *b) {
  return (struct node*) ((long long int) (a) ^ (long long int) (b));
}

void insert(int pos, int data) {
  struct node* newptr = (struct node*)malloc(sizeof(struct node));
  newptr->data = data;
  
  newptr->xnp = XOR(head, NULL);
  if(head == NULL){
    head = newptr;
    return;
  }

  if(pos == 1){
    struct node* next = XOR(head->xnp, NULL);
    head->xnp = XOR(next, newptr);
    head = newptr;
  }
  else {
    int count = 1;
    struct node *cur = head, *prev = NULL, *next=XOR(cur->xnp, prev);
    while(count < pos - 1) {
      prev = cur;
      cur = next;
      count++;
      next = XOR(cur->xnp, prev);
    }
    newptr->xnp = XOR(cur, next);
    cur->xnp = XOR(newptr, prev);
    if(next)// if next is not null, ie, insertion is not taking place at end
      next->xnp = XOR(newptr, XOR(cur, next->xnp));
  }
}

void traverse() {
  struct node *cur = head, *prev = NULL, *next;
  while(cur != NULL){
    printf("%d-->", cur->data);
    next = XOR(cur->xnp, prev);
    prev = cur;
    cur = next;
  }
  printf("NULL");
}

void delete(int pos){
  if(head == NULL)
    return;
  if(pos == 1){
    struct node* throw = head;
    struct node* next = XOR(head->xnp, NULL);
    head = next;
    if(head)
      head->xnp = XOR(head->xnp, throw);
    free(throw);
  }
  else {
    int count = 1;
    struct node *cur = head, *prev = NULL, *next = XOR(cur->xnp, prev);
    while(count < pos - 1) {
      prev = cur;
      cur = next;
      next = XOR(cur->xnp, prev);
      count++;
    }
    struct node *throw = next, *thrownext = XOR(throw->xnp, cur);
    cur->xnp = XOR(thrownext, prev);
    if(thrownext)
      thrownext->xnp = XOR(XOR(thrownext->xnp, next), cur);
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
