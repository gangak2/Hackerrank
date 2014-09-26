#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        long long int D;
        cin >> D;
        long long int K = sqrt(2*D);
        if(K*(K+1) == 2*D){
            cout << K << endl;
        }
        else{
            cout << "-1" << endl;
        }
    }
    return 0;
}
