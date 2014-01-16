#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

long long int *Fib;


// Approach 1, the special properties of fibonacci numbers (isSquare(5*N*N+4)||isSquare(5*N*N-4))
bool isFibo2(long long int test){
    long long int temp;
    test*=5*test;
    test+=4;
    temp = sqrt(test);
    if(temp*temp==test)  return true;
    else{
        test-=8;
        temp = sqrt(test);
        if(temp*temp==test)  return true;
    }
    return false;
}

//Approach 2 Implementing the binary search on the already computed Fibonacci numbers
bool isFibo(long long int test,int s, int l){
    if(s>l){
        return false;
    }
    if(Fib[(s+l)/2]==test){
        return true;
    }
    else {
        if(Fib[(s+l)/2]>test){
            return isFibo(test,s,(s+l)/2-1);
        }
        else
            return isFibo(test,(s+l)/2+1,l);
    }
}

// Compute the first 50 fibonacci numbers
long long int* CompFib(){
    long long int *r;
    r=(long long int*)malloc(50*sizeof(long long int));
    r[0]=0;
    r[1]=1;
    for(int i=2;i<50;i++){
        r[i]=r[i-1]+r[i-2];
    }
    return r;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int T;
    long long int test;
    scanf("%d",&T);
    Fib = (long long int*)malloc(50*sizeof(long long int));
    Fib = CompFib();
    printf("%lld\n",Fib[49]);
    while(T--){
        scanf("%lld",&test);
        if(isFibo(test,0,49)){  // for approach 2
        //if(isFibo2(test)){   //for approach 1 
            printf("IsFibo\n");
        }
        else{
            printf("IsNotFibo\n");
        }
    }
    return 0;
}
