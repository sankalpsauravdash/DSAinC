#include<stdio.h>
#include<stdlib.h>
struct node{
  struct node *prev;
  int data;
  struct node *next;
};

void traversal(struct node *head){
  struct node *p=head;
  printf("\n Traversal- \n");
  while(p!=NULL){
    printf(" %d",p->data);
    p=p->next;
  }
}
struct node *insertAtBegin(struct node *head,int data){
  struct node *ptr=(struct node *)malloc(sizeof(struct node));
  ptr->data=data;
  ptr->prev=NULL;
  head->prev=ptr;
  ptr->next=head;
  return ptr;
}

struct node *insertAtEnd(struct node *head,int data){
  struct node *ptr=(struct node *)malloc(sizeof(struct node));
  struct node *p=head;
  while(p->next!=NULL){
    p=p->next;
  }  
  p->next=ptr;
  ptr->prev=p;
  ptr->next=NULL;
  ptr->data=data;
  return head;
}

struct node *insertAtIndex(struct node *head,int data,int index){
  struct node *ptr=(struct node *)malloc(sizeof(struct node));
  struct node *p=head;
  struct node *q=head->next;
  for(int i=0;i<index-1;i++){
    p=p->next;
    q=q->next;
  }
  p->next=ptr;
  ptr->prev=p;
  q->prev=ptr;
  ptr->next=q;
  ptr->data=data;
  return head;
}

struct node *deleteBegin(struct node *head){
  struct node *p=head->next;
  p->prev=NULL;
  head->next=NULL;
  free(head);
  return p;
  }

struct node *deleteEnd(struct node *head){
  struct node *p=head;
  struct node *q=p->next;
  while(q->next!=NULL){
    p=p->next;
    q=q->next;
  }
  p->next=NULL;
  q->prev=NULL;
  free(q);
  return head;
}

struct node *deleteSpecific(struct node *head,int cdata){
  struct node *p=head;
  struct node *q=head->next;
  while(q->data!=cdata){
    p=p->next;
    q=q->next;
  }
  p->next=q->next;
  (q->next)->prev=p;
  free(q);
  return head;
  
}

struct node *deleteAtIndex(struct node *head,int index){
  struct node *p=head;
  struct node *q=head->next;
  for(int i=0;i<index-1;i++){
    p=p->next;
    q=q->next;
  }
  p->next=q->next;
  (q->next)->prev=p;
  free(q);
  return head;
}

struct node *insertAfter(struct node *head,int data,int val){
  struct node *ptr=(struct node *)malloc(sizeof(struct node));
  struct node *q=head;
  while(q->data!=val){
    q=q->next;
    }
  (q->next)->prev=ptr;
  ptr->next=(q->next);
  ptr->prev=q;
  q->next=ptr;
  ptr->data=data;
  return head;
} 

struct node *insertBefore(struct node *head,int data,int val){
  struct node *ptr=(struct node *)malloc(sizeof(struct node));
  struct node *q=head;
  while(q->data!=val){
    q=q->next;
  }
  (q->prev)->next=ptr;
  ptr->prev=q->prev;
  ptr->next=q;
  q->prev=ptr;
  ptr->data=data;
  return head;
  }


void prevtraversal(struct node *head){
  struct node *p=head;
  while(p->next!=NULL){
    p=p->next;
  }
  printf("\n Reverse Traversal- \n");
  while(p->prev!=NULL){
    printf(" %d",p->data);
    p=p->prev;
  }
  printf(" %d",p->data);
}
  
  int main(){
  struct node *head=(struct node *)malloc(sizeof(struct node));
  head->prev=NULL;
  head->data=34;
  head->next=NULL;
  traversal(head);
  head=insertAtBegin(head,89);
  traversal(head);
  head=insertAtEnd(head,67);
  traversal(head);
  head=insertAtIndex(head,78,2);
  traversal(head);
  head=insertAtEnd(head,75);
  traversal(head);
  head=insertAfter(head,88,67);
  traversal(head);
  head=insertBefore(head,776,88);
  traversal(head);
  //head=deleteBegin(head);
  //traversal(head);
  //head=deleteEnd(head);
  //traversal(head);
  //head=deleteSpecific(head,34);
  //traversal(head);
  //head=deleteAtIndex(head,2);
  //traversal(head);
  prevtraversal(head);

}