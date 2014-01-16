#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int *N;

bool FindNumber(int m, int mod, int pos, int places){
    if(mod==0)  return true;
     if(pos==places) return false;
    else{
        if(FindNumber(m,(mod*10)%m,pos+1,places)){
            N[pos]=0;
            return true;
        }
        if(FindNumber(m,(mod*10+9)%m,pos+1,places)){
            N[pos]=9;
            return true;
        }  
    }
    return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int T,m;
    N = (int*)malloc(50*sizeof(int));
    //I made an assumtion that for a given range of numbers, the corresponding X would not have more than 50 digits, turned out fine :)
    for(int i=1;i<50;i++){
        N[i]=1;
    }
    N[0]=9;
    cin >> T;
    while(T--){
        cin >> m;
        int j=1;
        while(!FindNumber(m,9%m,1,j++));
        for(int i=0;i<=j-2;i++){
            printf("%d",N[i]);
        }
        cout << endl;

    }
    return 0;
}
