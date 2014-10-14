#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int ModMult(int a, int b){
    int res = 0;
    while (a != 0) {
        if (a & 1) res = (res + b) % MOD;
        a >>= 1;
        b = (b << 1) % MOD;
    }
    return res;
}

int perimeter(int N){
    if(N==0)    return 1;
    if(N==1)    return 2;
    int C = perimeter(N/2)%MOD;
    int res = ModMult(C,C);
    if(N%2==0)  return res;
    else        return ModMult(res,2);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        int ans = ModMult(perimeter(N)-1,2)+4;
        cout << ans%MOD << endl;
    }
    return 0;
}
