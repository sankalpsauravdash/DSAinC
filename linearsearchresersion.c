#include<stdio.h>
#include<stdlib.h>
int LinearSearchR(int arr[], int length, int target) {
    int recur;
    length--;
 
    if (length >= 0) {
        if (arr[length] == target)
            return length;
        else
            recur = LinearSearchR(arr, length, target);
    }
    else
        return -1;
 
    return recur;
}

int main(){
    int arr[]={12,25,6,9,10,5},target;
    printf("\n Enter the number: ");
    scanf("%d",&target);
    int size_arr=sizeof(arr)/sizeof(arr[0]);
    
 printf("\n Using recursion : %d ",LinearSearchR(arr, size_arr, target));
        return 0;
}