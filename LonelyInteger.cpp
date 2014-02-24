/*
There are N integers in an array A. All but one integer occurs in pairs. Your task is to 
find out that number that occurs only once.

Input Format

The first line of the input contains an integer N indicating number of integers in the array 
A.
Next line contains N integers each separated by a single space.

Constraints

1 <= N < 100
N % 2 = 1 ( N is an odd number )
0 <= A[i] <= 100, ∀ i ∈ [1, N]

Output Format

Output (S) which is the number that occurs only once.

Sample Input:1

1
1
Sample Output:1

1
Sample Input:2

3
1 1 2
Sample Output:2

2
Sample Input:3

5
0 0 1 2 1
Sample Output:3

2
Explanation

In the first input, we see only 1 element and that element is the answer (1)
In the second input, we see 3 elements, 1 is repeated twice, the only other element 2 is the 
answer
In the third input, we see 5 elements, 1 and 0 are repeated twice, the other element 2 is 
the answer
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
int lonelyinteger(vector < int > a) {
    int result=0;
    for(int i=0;i<a.size();i++){
        result^=a[i];
    }
    return result;

}
/* Tail starts here */
int main() {
    int res;
    
    int _a_size;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    
    res = lonelyinteger(_a);
    cout << res;
    
    return 0;
}