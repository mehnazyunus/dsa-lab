#include <stdio.h>
#include <stdlib.h>

//Circular linked list
struct node {
  int data;
  struct node* next;
};

struct node* last = NULL;

void insert(int pos, int data) {
  struct node* newptr = (struct node*)malloc(sizeof(struct node*));
  newptr->data = data;

  if(last == NULL){
    last = newptr;
    last->next = last;
  }
  else if(pos == 1) {
    newptr->next = last->next;
    last->next = newptr;
  }
  else {
    struct node *cur = last, *temp = cur->next;
    int count = 0, total = 1;
    while(temp != last){
      total++;
      temp = temp->next;
    }    
    if(pos == total+1){ //insertion at the end
      newptr->next = last->next;
      last->next = newptr;
      last = newptr;
    }
    else {
      while(count < pos-1) {
        cur = cur->next;
        count++;
      }
      newptr->next = cur->next;
      cur->next = newptr;
    }
  }
}

void traverse() {
  
  if(last == NULL) {
    printf("List empty");
    return;
  }
  struct node* ptr = last->next;
  while(ptr != last){
    printf("%d --> ", ptr->data);
    ptr = ptr->next;
  }
  printf("%d -->front", ptr->data);
  
}

void delete(int pos) {
  int count = 1;
  struct node* throw;
  if(last == NULL)
    return;
  if(last->next == last) { //if only one element in list
    throw = last;
    free(throw);
    last = NULL;
    return;
  }
  if(pos == 1){
    throw = last->next;
    last->next = throw->next;
    free(throw);
  }
  else {
    struct node *temp = last->next, *cur = last;
    int total = 1, count = 0;
    while(temp != last){ //count no of elements
      total++;
      temp = temp->next;
    }
    while(count < pos-1) { //cur points to the element before element to be deleted
        cur = cur->next;
        count++;
      }  
    if(pos == total) //update last pointer if deletion from end
        last = cur;  
    throw = cur->next;
    cur->next = throw->next;
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
