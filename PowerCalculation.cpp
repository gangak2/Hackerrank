#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

long long int powermod100(long long int N, long long int K){
    if(K == 1 || N == 0)  return 1;
    if(N == 1)  return K;
    long long int temp = powermod100(N/2,K)%100;
    if(N%2 == 0)    return (temp*temp)%100;
    else    return (temp*temp*K)%100;       
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    while(T--){
        long long int N,K;
        cin >> K >> N;
        long long int *X;
        X = (long long int*)malloc(100*sizeof(long long int));
        X[0] = 1;
        for(int i=1;i<100;i++){
            X[i] = (X[i-1] + powermod100(N,i+1))%100;
        }
        long long int out = K%100>0?((K/100)*X[99] + X[(K%100)-1])%100:(K/100)*X[99]%100;
        if(out < 10)    cout << "0";
        cout << out << endl;
    }
    return 0;
}
