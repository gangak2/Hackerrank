/*
Jim is doing his discrete maths homework which requires him to repeatedly calculate 
nCr(n choose r) for different values of n. Knowing that this is time consuming, he goes to 
his sister June for help. June, being a computer science student knows how to convert this 
into a computer program and generate the answers quickly. She tells him, by storing the 
lower values of nCr(n choose r), one can calculate the higher values using a very simple 
formula.

If you are June, how will you calculate nCr values for different values of n?

Input Format
The first line contains the number of test cases T.
T lines follow each containing an integer n.

Output Format
For each n output the list of nC0 to nCn each separated by a single space in a new line. If 
the number is large, print only the last 9 digits. i.e. modulo 109

Constraints
1<=T<=200
1<=n< 1000

Sample Input

3
2
4
5
Sample Output

1 2 1
1 4 6 4 1
1 5 10 10 5 1
Explanation
For 2 we can check 2C0 2C1 and 2C2 are 1, 2 and 1 respectively. The other inputs’ answer 
follow similar pattern.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MOD 1000000000
using namespace std;


int main() {
    int T;
    int BinCoeffs[1001][1001];
    BinCoeffs[0][0]=1;
    BinCoeffs[1][0]=1;
    BinCoeffs[1][1]=1;
    for(int i=2;i<1001;i++){
        BinCoeffs[i][0]=1;
        for(int j=1;j<i;j++){
            BinCoeffs[i][j]=(BinCoeffs[i-1][j-1]+BinCoeffs[i-1][j])%MOD;
        }
        BinCoeffs[i][i]=1;
    }
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i=0;i<=n;i++){
            cout << BinCoeffs[n][i] << " ";
        }
        cout << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
