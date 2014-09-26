#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,*heights,height;
    heights = (int*)calloc(1001,sizeof(int));
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> height;
        heights[height]++;
    }
    cout << N << endl;
    for(int i=0;i<1001 && N>0;i++){
        if(heights[i]!=0){
            N-=heights[i];
            if(N!=0)    cout << N << endl;;
        }
    }
    return 0;
}
