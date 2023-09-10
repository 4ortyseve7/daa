//  0/1 Knapsack

#include <stdio.h>

int max(int a, int b)
{ 
    return((a > b) ? a : b); 
}

int knapSack(int W, int wt[], int val[], int n)
{
	
	if (n==0 || W==0)
		return 0;
	if (wt[n-1] > W)
		return knapSack(W, wt, val, n-1);
	else
		return max(val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),knapSack(W, wt, val, n-1));
}


int main()
{
	int n,W;
	printf("Enter total no of items : ");
	scanf("%d",&n);
	int profit[n];
	int weight[n];
	for(int i=0;i<n;i++){
		printf("Enter weight and profit of item %d : ",i+1);
		scanf("%d %d",&weight[i],&profit[i]);
	}
	printf("Enter the size of knapsack: ");
	scanf("%d",&W);

	printf("\nThe maximum profit in 0/1 knapSack is %d", knapSack(W, weight, profit, n));
	return 0;
}
