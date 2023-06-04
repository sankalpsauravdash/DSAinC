#include<stdio.h>
int insertion(int arr[],int size,int capacity,int element,int index)
{
	if(size>=capacity)
	{
		return -1;
	}
	for(int i=size-1;i>=index;i--)
	{
		arr[i+1]=arr[i];
	}
	arr[index]=element;
	return 1;
}
void  Deletion(int arr[], int size, int element)
{
    for (int i = element; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}
void display(int arr[],int n){
	for(int i=0;i<n;i++)
	{
		printf("%d",arr[i]);
	}printf("\n");
}
int main()
{
	int arr[100]={1,22,33,44,55};
	int size=5;int element; int index;int choice;int count;
	printf("1 for insersion\n");
    printf("2 for deletion\n");
    printf("3 for traversal\n");
    printf("Enter the choice\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter  the number you want to enter\n");
        scanf("%d", &index);
        printf("Enter the position you want to enter the number\n");
        scanf("%d", &element);
        count = insertion(arr, size, index, 100, element);
        if (count < 0)
        {
            printf("insertion failed\n");
            display(arr, size);
        }
        else
        {
            printf("insertion completed\n");
            size += 1;
            display(arr, size);
        }
        break;
    case 2:
        printf(" Define the position of the array element where you want to delete: \n ");
        scanf("%d",&element);
        Deletion(arr, size, element);
        size -= 1;
        display(arr, size);
        break;
    case 3:
        printf("Traversal of array is\n");
        display(arr,size);
    default:
        printf("Wrong Choice\n");
        return 0;
    }
}


