#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string text;

bool modifiedPatternSearch(int* freq, int start, int end){
    int *temp;
    temp = (int*)calloc(26,sizeof(int));
    for(int i=start;i<end;i++){
        temp[text[i]-97]++;
    }
    for(int i=0;i<26;i++){
        if(freq[i] != temp[i]){
            return false;
        }
    }
    return true;
}

int* prepareSubString(int start, int end){
    int* freq;
    freq = (int*)calloc(26,sizeof(int));
    for(int i=start;i<end;i++){
        freq[text[i]-97]++;
        //cout << text[i] << " " << freq[text[i]-97] << endl;
    }
    return freq;
}

int searchPairs(){
    int count=0;
    for(int j=1;j<=text.length();j++){
        for(int i=0;i<j;i++){
            int* freq = prepareSubString(i,j);
            for(int k=0;k<=text.length()-(j-i);k++){
                if(modifiedPatternSearch(freq,k,k+(j-i))){
                    count++;
                }
           }
           count--;
        }
    }
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int T;
    cin >> T;
    while(T--){
        cin >> text;
        cout << searchPairs()/2 << endl;
    }
    return 0;
}
