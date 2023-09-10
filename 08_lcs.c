//LCS

#include <stdio.h>
#include <string.h>

int i,j,m,n,c[20][20];
char x[20],y[20],b[20][20];

void printLCS(int i, int j)
{
    if(i==0 || j==0)
        return ;
    if(b[i][j] == 'c')
    {
        printLCS(i-1,j-1);
        printf("%c",x[i-1]);
    }
    else if(b[i][j] == 'u')
        printLCS(i-1,j);
    else
        printLCS(i,j-1);
}

void lcs()
{
    m = strlen(x);
    n = strlen(y);

    for(i=0;i<=m;i++)
        c[i][0] = 0;
    for(j=0;j<=n;j++)
    for(j=0;j<=n;j++)
        c[0][j] = 0;
    
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            if(x[i-1] == y[j-1])
            {
                c[i][j] = c[i-1][j-1]+1;
                b[i][j] = 'c';
            }
            else if(c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 'u';
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = 'l';
            }
        }
}

int main()
{
    printf("Enter 1st sequence: ");
    scanf("%s",x);
    printf("Enter 2nd sequence: ");
    scanf("%s",y);
    printf("\nThe largest common sub-sequence is: ");
    lcs();
    printLCS(m,n);
    return(0);
}
