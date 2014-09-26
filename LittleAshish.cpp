#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    while(T--){
        long long int X;
        cin >> X;
        long long int y = cbrt(3*X);
        if(((y)*(y+1)*(2*y+1))/6 <= X){
            cout << y << endl;
        }
        else{
            cout << y-1 << endl;
        }
    }
    return 0;
}
