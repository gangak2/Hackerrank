#include<stdio.h>

int max(int a, int b) { return (a > b)? a : b; }

int knapSack(int W, int val[], int n)
{
   int i, w;
   int K[n+1][W+1];

   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (val[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-val[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   return K[n][W];
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int N,G;
        scanf("%d%d",&N,&G);
        int arr[N],sum=0,i;
        for(i=0;i<N;i++){
            scanf("%d",&arr[i]);
            sum+=arr[i];
        }
        int val = knapSack(G, arr, N);
        if(sum -val > G){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
    return 0;
}
