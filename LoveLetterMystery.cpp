#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    while(T--){
        int cost=0;
        string test;
        cin >> test;
        long long int sum = 0;
        for(int i=0,j=test.length()-1;i<j;i++,j--){
            if(test[i]!=test[j])    sum += abs((int)test[i]-(int)test[j]);
        }
        cout << sum << endl;
    }
    return 0;
}
