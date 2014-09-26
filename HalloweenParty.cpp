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
        long long int K;
        cin >> K;
        long long int ans = (K/2)*(K-K/2);
        cout << ans << endl;
    }
    return 0;
}
