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
        string test;
        cin >> test;
        int sum=0,A=0,B=0;
        for(int i=0;i<test.length();i++){
            if(test[i]=='A'){
                sum+=((B>0)?(B-1):0);
                B=0;
                A++;
            }
            else if(test[i] == 'B'){
                sum+=((A>0)?(A-1):0);
                A=0;
                B++;
            }
        }
        sum+=((B>0)?(B-1):0);
        sum+=((A>0)?(A-1):0);
        cout << sum << endl;
    }
    return 0;
}
