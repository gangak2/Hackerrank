/*
The Indian bank issues coins in 4 denominations, ₹1, ₹2, ₹5 and ₹10.

Given a limited supply of each of the above denominations, in how many ways can you sum them 
up to a total of ₹N?

Input Format
The first line contains an integer T (number of testcases). Each testcase contains 2 lines. 
The first line contains integer N (sum to be achieved)
A, B, C and D in the next line, each representing the number of ₹1, ₹2, ₹5 and ₹10 coins 
respectively.

Output Format
Output the number of ways in which we can achieve the sum N.

Constraints
1 <= T <= 150
1 <= N <= 1000
1 <= A <= 10000
1 <= B,C,D <= 1000

Sample Input

2
15
2 3 1 1
12
2 2 1 1
Sample Output

2
2
Explanation
In the first case we need to find the different ways to total to 15. We can use one ₹10 
coin and one ₹5 coin or one ₹10 coin two ₹2 coin and one ₹1 coin. Proceed similarly for the 
second case.
*/

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
        int N;
        cin >> N;
        int a,b,c,d,count=0;
        cin >> a >> b >> c >> d;
        for(int one=0;one<=a;one++){
            for(int two=0;two<=b && two <= (N-one)/2;two++){
                for(int five=0;five<=c && five<=(N-one-2*two)/5;five++){
                    if((N-one-2*two-5*five)%10 == 0 && (N-one-2*two-5*five)/10<=d)    count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
