#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MOD 1000000000
using namespace std;


int main() {
    int T;
    int BinCoeffs[1001][1001];
    BinCoeffs[0][0]=1;
    BinCoeffs[1][0]=1;
    BinCoeffs[1][1]=1;
    for(int i=2;i<1001;i++){
        BinCoeffs[i][0]=1;
        for(int j=1;j<i;j++){
            BinCoeffs[i][j]=(BinCoeffs[i-1][j-1]+BinCoeffs[i-1][j])%MOD;
        }
        BinCoeffs[i][i]=1;
    }
    cin >> T;
    while(T--){
        int n,m;
        cin >> n >> m;
        cout << BinCoeffs[n+m-1][n-1] << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
