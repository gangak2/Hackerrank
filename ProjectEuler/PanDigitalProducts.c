#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int *arr,*duplicated,sum;

int sanity_check(int size){
    int i;
    for(i=0;i<size-1;i++){
        if(arr[i]<arr[i+1]){
            return 1;
        }
    }
    return 0;
}

void update(int size){
    int i;
    for(i=size-1;i>0;i--){
        if(arr[i]>arr[i-1]){
            int tmp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = tmp;
            break;
        }
        else continue;
    }
}

void swap (int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(int *arr, int start, int end, int size) 
{
   int k; 
   if (start == end){
       int Z=0,i,j;
        //compute the value of Z
        for(i=(size+1)/2;i<size;i++){
            Z*=10;
            Z+=arr[i];
        }
        //compute the values of X and Y
        //Setting the breakpoint
        for(i=1;i<(size+1)/2;i++){
            //compute the value of X
            int X=0;
            for(j=0;j<i;j++){
                X*=10;
                X+=arr[j];
            }
            //compute the value of Y
            int Y=0;
            for(j=i;j<(size+1)/2;j++){
                Y*=10;
                Y+=arr[j];
            }
            //check for the condition X*Y = Z
            if(X*Y == Z){
                //discard the dduplicacy
                if(duplicated[Z]!= 1){
                    sum+=Z;
                    duplicated[Z]=1;
                }
            }
        }
   }
   else
   {
        for (k = start; k <= end; k++)
       {
          swap((arr+start), (arr+k));
          permute(arr, start+1, end, size);
          swap((arr+start), (arr+k)); //backtrack
       }
   }
} 



int main(){
    int N;
    scanf("%d",&N);
    arr = (int*)malloc(N*sizeof(int));
    duplicated = calloc(pow(10,(N+1)/2),sizeof(int));
    int i;
    for(i=0;i<N;i++){
        arr[i]=i+1;
    }
    sum=0;
    permute(arr,0,N-1,N);
    printf("%d\n",sum);
    return 0;
}
