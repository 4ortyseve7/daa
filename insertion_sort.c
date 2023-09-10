//Insertion Sort using an array
#include<stdio.h>
//logic of sorting
void insertionsort(int arr[],int i,int j)
{
    for(int k=i;k<j;k++)
    {
       int temp = arr[k+1];
       int p = k;
       while(p>=0 && arr[p]>temp)
       {
          arr[p+1] = arr[p];
          p--;
       }
       arr[p+1] = temp;
    }
}
int main()
{
    int r,i;
    printf("Enter the size of an array\n");
    scanf("%d",&r);
    int arr[r];
    printf("Enter the elements in an array\n");
    for(i=0;i<r;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("The given array is:\n");
    for(i=0;i<r;i++)
    {
        printf("%d ",arr[i]);
    }
    insertionsort(arr,0,r-1);
    printf("\nThe array after sorting\n");
    for(i=0;i<r;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
