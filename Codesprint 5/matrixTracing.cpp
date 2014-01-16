#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define p 1000000007

long long int power(long long int a, long long int b, long long int MOD) {
	long long int x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}

long long int modInverse(long long int q, long long int r) {
	long long int itermi,outmi=1;
	for(itermi=1;itermi<=q;itermi++)
	    outmi = (outmi*power(itermi,r-2,r))%r;
	return outmi;
}

long long int modMultiplication(long long int a,long long int b, long long int m){
	long long int itermm,outmm=1;
	for(itermm=0;itermm<b;itermm++)
		outmm = outmm*(a-itermm)%m;
	//printf("%d\n",outmm);
	return outmm;
}

long long int permutations(long long int x, long long int y, long long int z){
	long long int t1,t2;
	if(y<=x/2){
		t1 = modMultiplication(x,y,z);
		t2 = modInverse(y,z);
	}
	else{
		t1 = modMultiplication(x,x-y,z);
		t2 = modInverse(x-y,z);
	}
	return (t1*t2)%z;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    long long int m,n,res;
    cin >> T;
    while(T--){
        cin >> m >> n;
        res = permutations(m+n-2,n-1,p);
        cout << res << endl;
    }
    return 0;
}
