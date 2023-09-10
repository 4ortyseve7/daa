// Merge Sort in an Array.

#include<stdio.h>

int Merging(int A[], int low1, int up1, int low2, int up2){
   
    int art1[up1-low1+1],art2[up2-low2+1],length=up2-low1+1;
    for(int i=0; i<up1-low1+1; i++){
        art1[i] = A[low1+i];
        art2[i] = A[low2+i];
    }
   
    int i=0,j=0,k=0;
    while(i<up1-low1+1 && j<up2-low2+1){
        if(art1[i] < art2[j]){
            A[k+low1] = art1[i++];
        }
        else{
            A[k+low1] = art2[j++];
        }
        k++;
    }
    while(i<up1-low1+1){
        A[k+low1] = art1[i++];
        k++;
    }
    while(j<up2-low2+1){
        A[k+low1] = art2[j++];
        k++;
    }
}
int MergeSort(int A[], int low, int up){
    int mid = ( low + up ) / 2 ;
    if ( low == up ){
        return(A[low]);
    }
    else{
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,up);

        Merging(A,low,mid,mid+1,up);
    }
}

void PrintArray(int arr[],int length){
    for(int i=0;i<length;i++){
        printf(" %d",arr[i]);
    }
}
int main(){
    int length;
    printf("Enter the size of the array to create : ");
    scanf(" %d",&length);
    int arr[length];

    printf("Enter the values into the array\n");
    for(int i=0;i<length;i++){
        scanf("%d",&arr[i]);
    }
    
    printf("\nThe array you created is :\n");
    PrintArray(arr,length);
    
    MergeSort(arr,0,length-1);
    
    printf("\nThe Sorted Array is :\n");
    PrintArray(arr,length);
    
    return(0);
}
