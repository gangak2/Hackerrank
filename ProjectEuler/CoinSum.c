#include<stdio.h>
#include<stdlib.h>

#define p 1000000007

int **table;
    
void count( int S[], int m, int n )
{
    int i, j, x, y;
    
    // Fill the enteries for 0 value case (n = 0)
    for (i=0; i<m; i++)
        table[0][i] = 1;
 
    // Fill rest of the table enteries in bottom up manner  
    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            // Count of solutions including S[j]
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;
 
            // Count of solutions excluding S[j]
            y = (j >= 1)? table[i][j-1]: 0;
 
            // total count
            table[i][j] = (x + y)%p;
        }
    }
}
 
// Driver program to test above function
int main()
{
    int arr[] = {1, 2, 5, 10, 20, 50, 100, 200};
    int m = sizeof(arr)/sizeof(arr[0]);
    int T, n, i;
    table = (int**)malloc(100001*sizeof(int*));
    for(i=0;i<=100000;i++){
        table[i] = (int*)malloc(m*sizeof(int));
    }
    count(arr,m,100000);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        
        printf("%d\n",table[n][m-1]);
    }
    return 0;
}
