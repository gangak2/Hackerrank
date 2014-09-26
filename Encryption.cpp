#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    string test;
    cin >> test;
    int n = sqrt(test.length()-1)+1;
    for(int i=0;i<n;i++){
        for(int j=0;j*n+i<test.length();j++){
            cout << test[j*n+i];
        }
        cout << " ";
    }
    return 0;
}
