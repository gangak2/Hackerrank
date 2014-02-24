/*
King Robert has 7 kingdoms under his rule. He gets to know from Raven that the Dothraki are 
to wage a war against him soon. But, he knows the Dothraki need to cross the narrow river 
to enter his dynasty. There is only one bridge that connects both sides of the river which 
is sealed by a huge door.

door

The king wants to lock the door so that the Dothraki can’t enter. But, to lock the door you 
need a key that is an anagram of a certain palindrome string.

The king has a list of words. For each given word, can you help the king in figuring out if 
any anagram of it can be a palindrome or not?.

Input Format
A single line which will contain the input string

Constraints
1<=length of string <= 10^5 Each character of the string is a lowercase english alphabet.

Output Format
A single line containing YES/NO in capital letter of english alphabet.

Sample Input : 01

aaabbbb
Sample Output : 01

YES
Explanation
One of the permutations of the given string which is a palindrome is bbaaabb. 

Sample Input : 02

cdefghmnopqrstuvw
Sample Output : 02

NO
Explanation
You can verify that no permutation of the given string can be a palindrome. 

Sample Input : 03

cdcdcdcdeeeef
Sample Output : 03

YES
Explanation
One of the permutations of the given string which is a palindrome is ddcceefeeccdd .
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    string input;
    int frequency[26];
    for(int i=0;i<26;i++){
        frequency[i]=0;
    }
    cin >> input;
    for(int i=0;i<input.length();i++){
        switch(input[i]){
            case 'a' : {frequency[0]++;continue;}
            case 'b' : {frequency[1]++;continue;}
            case 'c' : {frequency[2]++;continue;}
            case 'd' : {frequency[3]++;continue;}
            case 'e' : {frequency[4]++;continue;}
            case 'f' : {frequency[5]++;continue;}
            case 'g' : {frequency[6]++;continue;}
            case 'h' : {frequency[7]++;continue;}
            case 'i' : {frequency[8]++;continue;}
            case 'j' : {frequency[9]++;continue;}
            case 'k' : {frequency[10]++;continue;}
            case 'l' : {frequency[11]++;continue;}
            case 'm' : {frequency[12]++;continue;}
            case 'n' : {frequency[13]++;continue;}
            case 'o' : {frequency[14]++;continue;}
            case 'p' : {frequency[15]++;continue;}
            case 'q' : {frequency[16]++;continue;}
            case 'r' : {frequency[17]++;continue;}
            case 's' : {frequency[18]++;continue;}
            case 't' : {frequency[19]++;continue;}
            case 'u' : {frequency[20]++;continue;}
            case 'v' : {frequency[21]++;continue;}
            case 'w' : {frequency[22]++;continue;}
            case 'x' : {frequency[23]++;continue;}
            case 'y' : {frequency[24]++;continue;}
            case 'z' : {frequency[25]++;continue;}
        }
    }
    int anomaly=0;
    for(int i=0;i<26;i++){
        if(frequency[i]%2!=0){
            anomaly++;
        }
    }
    if(anomaly<2){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}