#include<stdio.h>
#include<stdlib.h>

int powers[10];

void compute_powers(int K){
    int i,j;
    powers[0]=0;
    powers[1]=1;
    for(i=2;i<10;i++){
        powers[i]=1;
        for(j=0;j<K;j++){
            powers[i]*=i;
        }
    }
}

int search_numbers(int K){
    int sum=0,i;
    for(i=10;i<(K+1)*powers[9];i++){
        int z = i,num=0;
        while(z!=0){
            num+=powers[z%10];
            z/=10;
        }
        if(num==i){
            sum+=num;
        }
    }
    return sum;
}

int main(){
    int T;
    scanf("%d",&T);
    compute_powers(T);
    printf("%d\n",search_numbers(T));
    return 0;
}
