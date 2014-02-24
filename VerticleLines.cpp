/*
Given array of integers Y=y1,…,yn, we have n line segments such that endpoints of segment i 
are (i, 0) and (i, yi). Imagine that from the top of each segment a horizontal ray is shot 
to the left, and this ray stops when it touches another segment or it hits the y-axis. We 
construct an array of n integers, v1, …, vn, where vi is equal to length of ray shot from 
the top of segment i. We define V(y1, …, yn) = v1 + … + vn.

For example, if we have Y=[3,2,5,3,3,4,1,2], then v1, …, v8 = [1,1,3,1,1,3,1,2], as shown 
in the picture below:



For each permutation p of [1,…,n], we can calculate V(yp1, …, ypn). If we choose a 
uniformly random permutation p of [1,…,n], what is the expected value of V(yp1, …, ypn)?

Input Format

First line of input contains a single integer T (1 <=T<= 100). T test cases follow.

First line of each test-case is a single integer N (1 <= N <= 50). Next line contains 
positive integer numbers y1, …, yN separated by a single space (0 < yi <= 1000).

Output Format

For each test-case output expected value of V(yp1, …, ypn), rounded to two digits after the 
decimal point.

Sample Input

6

3

1 2 3

3

3 3 3

3

2 2 3

4

10 2 4 4

5

10 10 10 5 10

6

1 2 3 4 5 6

Sample Output

4.33

3.00

4.00

6.00

5.80

11.15

Explanation
 

Case 1: We have_ V(1,2,3) = 1+2+3 = 6, _V(1,3,2) = 1+2+1 = 4, V(2,1,3) = 1+1+3 = 5, V(2,3,1) 
= 1+2+1 = 4, V(3,1,2) = 1+1+2 = 4, V(3,2,1) = 1+1+1 = 3. Average of these values is 4.33.
Case 2: No matter what the permutation is, V(yp1, yp2, yp3) = 1+1+1 = 3, so the answer is 
3.00.
Case 3: V(y1 ,y2 ,y3)=V(y2 ,y1 ,y3) = 5, V(y1, y3, y2)=V(y2, y3, y1) = 4, V(y3, y1, y2)=
V(y3, y2, y1) = 3, and average of these values is 4.00.
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
        int heights[N];
        double occurences[N];
        for(int i=0;i<N;i++){
            cin >> heights[i];
        }
        sort(heights,heights+N);
        occurences[0]=N;
        double expectations=0.00;
        expectations+=(1/(occurences[0]+1));
        for(int i=1;i<N;i++){
            if(heights[i-1]==heights[i]){
                occurences[i]=occurences[i-1];
            }
            else{
                occurences[i]=N-i;
            }
            expectations+=(1/(occurences[i]+1));
        }
        expectations*=(double)(N+1);
        printf("%.2f\n",expectations);
    }
    return 0;
}
