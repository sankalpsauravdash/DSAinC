#include<stdio.h>
#include<stdlib.h>
int stack[100];
int top=-1;
void push()
{
	if(top==100-1)
	{
		printf("\n overflow \n");
	}
	else
	{
		int ch;
		printf("enter a element");
		scanf("%d",&ch);
		top++;
		stack[top]=ch;
	}
}

void pop()
{
	if(top==-1)
	{
		printf("underflow");
		
	}
	else
	{
		printf("Element deleted is %d",stack[top]);
		top--;
		
	}
}
void traverse()
{
	for(int i=top;i>=0;i--)
	{
		printf("\n%d",stack[i]);
	}
}
int main()
{	while(1){
	int choice;
	printf("\n 1:For Push \n 2:For Pop \n 3:Traversal \n 4:For Exit \n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:push();
				break;
		case 2:pop();
				break;
		case 3:traverse();
				break;
		case 4:	exit(0);
				break;
		default:printf("Invalid Entry");
	}
}

}



