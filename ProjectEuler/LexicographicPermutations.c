#include <stdio.h>
#include <stdlib.h>

int main(){
	char arr[] = "abcdefghijklm";
	int i;
    int size=13;
	long long int facts[size];
	facts[0]=1;
	for(i=1;i<size;i++){
		facts[i]=facts[i-1]*i;
	}
	int T;
	scanf("%d",&T);
	while(T--){
        int *used;
        used = (int*)calloc(size,sizeof(int));
		long long int N;
		scanf("%lld",&N);
		N-=1;
		for(i=size-1;i>=0;i--){
			int t = N/facts[i];
			int count=-1,j=0;
			while(count!=t){
				if(used[j]==0){
					count++;
				}
				j++;
			}
			printf("%c",arr[j-1]);
			used[j-1]=1;
			N%=facts[i];
		}
        printf("\n");
	}
	return 0;
}
