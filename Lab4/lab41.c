#include<stdio.h>
#include<stdlib.h>
//Doubly Linked list
struct node {
  int data;
  struct node* prev;
  struct node* next;
};

struct node* head = NULL;

void insert(int pos, int data) {
  struct node* newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data = data;
  newnode->prev = NULL;
  newnode->next = NULL;
  if(head == NULL)
    head = newnode;
  else if(pos == 0) {
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
  }
  else {
    int count = 0;
    struct node* cur = head;
    while(count < pos-1 && cur != NULL) {
      cur = cur->next;
      count++;
    }
    struct node* temp = cur->next;
    if(cur->next != NULL)
      temp->prev = newnode;
    cur->next = newnode;
    newnode->next = temp;
    newnode->prev = cur;

  }
}

void delete(int pos) {
  int count = 0;
  if(head == NULL)
    return;
  if(pos == 0) {
    struct node* temp = head;
    head = head->next;
    if(head != NULL)
      head->prev = NULL;
    free(temp);
  }
  else {
    struct node* temp = head;
    while(count < pos-1 && temp != NULL) {
      temp = temp->next;
      count++;
    }
    struct node* throw = temp->next;
    temp->next = throw->next;
    if(throw->next != NULL)
      throw->next->prev = temp;
    free(throw);
  }
}

void traverse() {
  struct node* ptr = head;
  while(ptr != NULL) {
    printf("%d <==> ", ptr->data);
    ptr = ptr->next;
  }
   printf("NULL");
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
