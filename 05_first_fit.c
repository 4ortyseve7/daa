//First fit

#include <stdio.h>

int firstFit(int item[], int bin_size, int n)
{
    int bin_count = 0;
    int item_count = n;
    
    int bin_arr[n];
    for(int i=0; i<n; i++)
        bin_arr[i] = bin_size;
    
    while(item_count)
    {
        for(int i=0; i<n; i++)
            for(int j=0; i<n; j++)
                if(bin_arr[j] >= item[i])
                {
                    bin_arr[j] -= item[i];
                    item_count--;
                    bin_count = (( j >= bin_count )? j : bin_count );
                    break;
                }
    }
    return bin_count+1;
}

int main() {
    int n, bin_size;
    printf("Enter the number of items : ");
    scanf("%d",&n);
    
    int item[n];
    printf("Enter the weights for\n");
    for(int i=0;i<n;i++)
    {
        printf("item %d : ",i+1);
        scanf("%d",&item[i]);
    }
    
    printf("Enter the size of bin : ");
    scanf("%d",&bin_size);
    
    printf("Total no of Bins required = %d", firstFit(item, bin_size, n));

    return 0;
}
