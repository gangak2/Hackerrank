/*
Alice recently started learning about cryptography and found that anagrams are very useful. 
Two strings are anagrams of each other if they have same character set. For example strings 
"bacdc" and "dcbac" are anagrams, while strings "bacdc" and "dcbad" are not.

Alice decides on an encryption scheme involving 2 large strings where encryption is 
dependent on the minimum number of character deletions required to make the two strings 
anagrams. She need your help in finding out this number.

Given two strings (they can be of same or different length) help her in finding out the 
minimum number of character deletions required to make two strings anagrams. Any characters 
can be deleted from any of the strings.

Input Format
Two lines each containing a string.

Constraints
1 <= Length of A,B <= 10000
A and B will only consist of lowercase latin letter.

Output Format
A single integer which is the number of character deletions.

Sample Input #00:

cde
abc
Sample Output #00:

4
Explanation #00:
We need to delete 4 characters to make both strings anagram i.e. ‘d’ and ‘e’ from first 
string and ‘b’ and ‘a’ from second string.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int* Compute(string S){
    int *A;
    A=(int*)calloc(26,sizeof(int));
    for(int i=0;i!=S.length();i++){
        switch(S[i]){
            case 'a' : {A[0]++;continue;}
            case 'b' : {A[1]++;continue;}
            case 'c' : {A[2]++;continue;}
            case 'd' : {A[3]++;continue;}
            case 'e' : {A[4]++;continue;}
            case 'f' : {A[5]++;continue;}
            case 'g' : {A[6]++;continue;}
            case 'h' : {A[7]++;continue;}
            case 'i' : {A[8]++;continue;}
            case 'j' : {A[9]++;continue;}
            case 'k' : {A[10]++;continue;}
            case 'l' : {A[11]++;continue;}
            case 'm' : {A[12]++;continue;}
            case 'n' : {A[13]++;continue;}
            case 'o' : {A[14]++;continue;}
            case 'p' : {A[15]++;continue;}
            case 'q' : {A[16]++;continue;}
            case 'r' : {A[17]++;continue;}
            case 's' : {A[18]++;continue;}
            case 't' : {A[19]++;continue;}
            case 'u' : {A[20]++;continue;}
            case 'v' : {A[21]++;continue;}
            case 'w' : {A[22]++;continue;}
            case 'x' : {A[23]++;continue;}
            case 'y' : {A[24]++;continue;}
            case 'z' : {A[25]++;continue;}
        }
    }
    return A;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    string S;
    int *F,*L;
    getline(cin,S);
    F = Compute(S);
    getline(cin,S);
    L = Compute(S);
    int sum=0;
    for(int i=0;i<26;i++){
        sum+=abs(F[i]-L[i]);
    }
    cout << sum << endl;
    return 0;
}
