/*
Red John has committed another murder. But this time, he doesn’t leave a red smiley behind. 
What he leaves behind is a puzzle for Patrick Jane to solve. He also texts Teresa Lisbon 
that if Patrick is successful, he will turn himself in. The puzzle begins as follows.

There is a wall of size CxN in the victim’s house where C is the 1st composite number. The 
victim also has an infinite supply of bricks of size Cx1 and 1xC in her house. There is a 
hidden safe which can only be opened by a particular configuration of bricks on the wall. 
In every configuration, the wall has to be completely covered using the bricks. There is a 
phone number written on a note in the safe which is of utmost importance in the murder case. 
Gale Bertram wants to know the total number of ways in which the bricks can be arranged on 
the wall so that a new configuration arises every time. He calls it M. Since Red John is 
back after a long time, he has also gained a masters degree in Mathematics from a reputed 
university. So, he wants Patrick to calculate the number of prime numbers (say P) up to M 
(i.e. <= M). If Patrick calculates P, Teresa should call Red John on the phone number from 
the safe and he will surrender if Patrick tells him the correct answer. Otherwise, Teresa 
will get another murder call after a week.

You are required to help Patrick correctly solve the puzzle.

Sample Input
The first line of input will contain an integer T followed by T lines each containing an 
integer N.

Sample Output
Print exactly one line of output for each test case. The output should contain the number P.

Constraints
1<=T<=20
1<=N<=40

Sample Input

2
1
7
Sample Output

0
3
Explanation

For N = 1, the brick can be laid in 1 format only

Red John1

The number of primes <= 1 is 0 and hence the answer.

For N = 7, one of the ways in which we can lay the bricks is

Red John
There are 5 ways of arranging the bricks for N = 7 and there are 3 primes <= 5 and hence the 
answer 3.
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
    /*PREPROCESSING OF DATA*/
    int ways[41];
    int primes[217287],flag=0;
    primes[0]=0;
    primes[1]=0;
    primes[2]=1;
    primes[3]=1;
    for(int i=4;i<217287;i++){
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0){
                flag=1;
                primes[i]=0;
                break;
            }
            else{
                continue;
            }
        }
        if(flag==0){
            primes[i]=1;
        }
        else{
            flag=0;
        }
    }
    ways[0]=ways[1]=ways[2]=ways[3]=1;
    ways[4]=2;
    for(int i=5;i<41;i++){
        ways[i]=ways[i-1]+ways[i-4];
    }
    while(T--){
        int N;
        cin >> N;
        int sum=0;
        for(int i=0;i<=ways[N];i++){
            if(primes[i]==1) sum++;
        }
        cout << sum << endl;
    }
    return 0;
}
