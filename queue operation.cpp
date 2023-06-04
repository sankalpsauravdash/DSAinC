#include<stdio.h>
#include<stdlib.h>
#define Size 5
int Queue[Size];
int front=-1;
int rear=-1;
void enQueue()
{  int n; 
  if(rear==Size-1){printf("OVERFLOW");}
  else
  {
    if(front==-1)
    {
      front++;  
    }
    printf("\nEnter value\n");
    scanf("%d",&n);
    rear++;
    Queue[rear]=n;
  }
  
}
void deQueue()
{
  if(front==rear)
  {printf("\nUnderflow!!\n");
  }
  else{
    printf("\nELement deleted is %d\n",Queue[front]);
    front++;
  }
}
void traverse()
{  printf("\n");
  for(int i=front;i!=rear+1;i++)
  {printf(" %d ",Queue[i]);
  }
}
void showvalue(){
  printf("\nfront=%d\n",front);
  printf("\nrear=%d\n",rear);
}

int main()
{  while(1){
  int choice;
  printf("\n 1:For enQueue \n 2:For deQueue \n 3:Traversal \n 4:For Exit \n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:enQueue();
        break;
    case 2:deQueue();
        break;
    case 3:traverse(); 
        showvalue();
        break;
    case 4:  exit(0);
        break;
    default:printf("Invalid Entry");
  }   
}

  
}
