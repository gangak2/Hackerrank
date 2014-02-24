/*
Given N integers, count the total pairs of integers that have a difference of K.

Input Format 
1st line contains N & K (integers).
2nd line contains N numbers of the set. All the N numbers are assured to be distinct.

Output Format
One integer saying the number of pairs of numbers that have a diff K.

Constraints:
N <= 10^5
0 < K < 10^9
Each integer will be greater than 0 and at least K away from 2^31-1

Sample Input #00:

5 2  
1 5 3 4 2  
Sample Output #00:

3
Sample Input #01:

10 1  
363374326 364147530 61825163 1073065718 1281246024 1399469912 428047635 491595254 879792181 
1069262793 
Sample Output #01:

0
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

int pairs(vector < int > a,int k) {
   int ans=0;
    sort(a.begin(),a.end());
    for(int i=0;i<a.size()-1;i++){
        for(int j=i+1;a[j]-a[i]<=k && j<a.size();j++){
            if(a[j]-a[i]==k)    ans++;
        }
    }
    return ans;
}

/* Tail starts here */
int main() {
    int res;
    
    int _a_size,_k;
    cin >> _a_size>>_k;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    
    res = pairs(_a,_k);
    cout << res;
    
    return 0;
}