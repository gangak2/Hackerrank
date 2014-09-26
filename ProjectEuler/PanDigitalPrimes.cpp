#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<long long int> PanDigitPrimes;

bool isprime(long long int K){
    for(int i=2;i<sqrt(K);i++){
        if(K%i == 0)    return false;
    }
    return true;
}

void swap (int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(int *arr, int start, int end, int size)
{
   int k;
   if (start == end){
       long long int Z=0;
       int i;
       for(i=0;i<size;i++){
           Z*=10;
           Z+=arr[i];
       }
       if(isprime(Z)){
           //cout << Z << endl;
           PanDigitPrimes.push_back(Z);
       }
   }
   else
   {
        for (k = start; k <= end; k++)
       {
          swap((arr+start), (arr+k));
          permute(arr, start+1, end, size);
          swap((arr+start), (arr+k)); //backtrack
       }
   }
}



int main(){
    int T;
    cin >> T;
    for(int i=3;i<10;i++){
        int *arr;
        arr = (int *)malloc(i*sizeof(int));
        for(int j=0;j<i;j++){
            arr[j] = j+1;
        }
        permute(arr,0,i-1,i);
        free(arr);
    }
    sort(PanDigitPrimes.begin(),PanDigitPrimes.end());
    while(T--){
        long long int N;
        cin >> N;
        long long int ans = -1;
        for(int i=0;PanDigitPrimes[i]<=N;i++){
            ans = PanDigitPrimes[i];
            if(i == PanDigitPrimes.size()-1){
                break;
            }
        }
        cout << ans << endl;
    }
}
