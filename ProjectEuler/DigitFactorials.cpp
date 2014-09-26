#include<stdio.h>
#include<stdlib.h>

int *facts;

int* factorials(){
    int i;
    int *fact;
    fact = (int*)malloc(10*sizeof(int));
    fact[0]=1;
    for(i=1;i<10;i++){
        fact[i]=i*fact[i-1];
    }
    return fact;
}

int getsum(int K){
    int sumfact=0;
    while(K!=0){
        sumfact+=facts[K%10];
        K/=10;
    }
    return sumfact;
}

int main(){
    int i,N,sum=0;
    facts = (int*)malloc(10*sizeof(int));
    facts = factorials();
    scanf("%d",&N);
    for(i=10;i<N;i++){
        if(getsum(i)%i == 0){
            sum+=i;
        }
    }
    printf("%d\n",sum);
}
