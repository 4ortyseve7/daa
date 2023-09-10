//MCM
#include <stdio.h>
int MCM(int arr[],int n)
{
    int minMul[n][n];
    int j,q;
    for(int i=1;i<n;i++)
        minMul[i][i] = 0;
    for(int l=2;l<n;l++)
    {
        for(int i=1;i<n-l+1;i++)
        {
            j = i+l-1;
            minMul[i][j] = 9999999;
            for(int k=i;k<=j;k++)
            {
                q = minMul[i][k] + minMul[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if(q<minMul[i][j])
                    minMul[i][j] = q;
            }
        }
    }
    return minMul[1][n-1];
}
int main(){
    int arr[] = {3,4,5,6,7,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Minimum no of multiplications required for the matrices multiplication is %d.",MCM(arr,size));

    return(0);
}
