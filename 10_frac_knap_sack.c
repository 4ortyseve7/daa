//fractional fractionalKnapsack

#include <stdio.h>

int max_index(double pro[], int n)
{   
    int max = 0;
    for(int i=1;i<n;i++)
    {
        if(pro[max]<pro[i])
        {
            max = i;
        }
    }
    return max;
}
double fractionalKnapsack(int W, double wt[], double val[], int N)
{   
    int index;
    
    double profit_P[N],frac_KS_Profit = 0;
    for(int i=0;i<N;i++)
    {
        profit_P[i] = val[i] /wt[i];
    }
    
    while(W>0)
    {
        index = max_index(profit_P, N);
        
        if(wt[index] <= W)
        {
            frac_KS_Profit += val[index];
        }
        else
        {
            frac_KS_Profit += ((W/wt[index])*val[index]);
        }
        
        W -= wt[index];
        profit_P[index] = -1;
    }
    return frac_KS_Profit;
}

int main()
{
    int N;
    double W;

    printf("Enter the no of items : ");
    scanf(" %d",&N);
    double item_P[N],item_W[N];
    
    for(int i=0;i<N;i++)
    {
        printf("Enter weight and profit of item %d : ",i+1);
        scanf("%lf %lf",&item_W[i],&item_P[i]);
    }
    
    printf("Enter the weight of Knapsack : ");
    scanf(" %lf",&W);
    
    printf("The maximum profit in fractional Knapsack is %lf", fractionalKnapsack(W, item_W, item_P, N));
    return 0;
}
