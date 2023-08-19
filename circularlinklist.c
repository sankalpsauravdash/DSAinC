#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
void traversal(struct node * head){
    struct node * ptr= head;
    do{
        printf("element: %d",ptr->next);
        ptr=ptr->next;
    }while(ptr!=head);
}
struct node * insertatfirst(struct node * head,int data){
    struct node * ptr =(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    struct node * p= head->next;
    while(p->next!=head)
    {
        p=p->next;

    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return ptr;
}
int main(){
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = head;

    printf("Linked list before insertion\n");
    traversal(head);
    head = insertatfirst(head, 54);
    head = insertatfirst(head, 58);
    head = insertatfirst(head, 59);
    printf("Circular Linked list after insertion\n");
    traversal(head);

    return 0;
}