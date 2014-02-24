/*
Find the no of positive integral solutions for the equations (1/x) + (1/y) = 1/N! (read 1 by 
N factorial) Print a single integer which is the no of positive integral solutions modulo 
1000007.

Input:
N 
Output:
Number of positive integral solutions for (x,y) modulo 1000007
Constraints:
1 <= N <= 10^6 
Sample Input00:
1

Sample Output00:
1

 

Sample Input01:

32327

Sample Output 01:

656502

Sample Input02:

40921

Sample Output 02:

686720
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define MOD 1000007
using namespace std;

unsigned int multmod(unsigned int a, unsigned int b, unsigned int m)
{
    unsigned int result = 0;

    a %= m;
    b %= m;

    while (b)
    {
        if (b % 2 != 0)
        {
            result = (result + a) % m;
        }

        a = (a * 2) % m;
        b /= 2;
    }

    return result;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N;
    cin >> N;
    int prime;
    unsigned int ways=1,sum;
    for(int i=2;i<=N;i++){
        sum=0;
        prime=0; 
        for(int j=2;j<=sqrt(i);j++){
            if(i%j != 0){
                continue;
            }
            else{
                prime=1;
                break;
            }
        }
        if(prime==0 || i==2){
            for(int j=1;pow(i,j)<=N;j++)   sum+=(N/pow(i,j));
            ways = multmod(ways,2*sum+1,MOD);
        }
        else{
            continue;
        }
    }
    cout << ways <<endl;                                             
    return 0;
}
