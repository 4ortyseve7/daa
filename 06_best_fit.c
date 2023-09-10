//bestFit

#include <stdio.h>

int bestFit(int item[], int bin_size, int n)
{
    int bin_count = 0;
    int item_count = n;
    
    int bin_arr[n];
    for(int i=0; i<n; i++)
        bin_arr[i] = bin_size;
    
    while(item_count)
    {
        int pos = 0,empty = bin_size;
        int bf;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=bin_count+1; j++)
            {
                if(bin_arr[j]-item[i] == 0)
                {
                    bf = 0;
                    bin_arr[j] -= item[i];
                    item_count--;
                    bin_count = (( j >= bin_count )? j : bin_count );
                    break;
                }
                else if(bin_arr[j]-item[i] > 0)
                {
                    bf = 1;
                    if(bin_arr[j]-item[i] < empty)
                    {
                        empty = bin_arr[j]-item[i];
                        pos = j;
                    }
                }
            }
            if(bf)
            {
                bin_arr[pos] -= item[i];
                item_count--;
                bin_count = (( pos >= bin_count )? pos : bin_count );
            }
            bf = 0;
            pos = 0;
            empty = bin_size;
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
    
    printf("Total no of Bins required = %d", bestFit(item, bin_size, n));

    return 0;
}
