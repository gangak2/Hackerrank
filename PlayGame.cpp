#include <cmath> 
#include <cstdio>
#include <vector>
#include <iostream> 
#include <algorithm> 

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        long long int *arr,*sum,*maxsum;
        arr = (long long int*)malloc(N*sizeof(long long int));
        sum = (long long int*)malloc(N*sizeof(long long int));
        maxsum = (long long int*)malloc(N*sizeof(long long int));
        for(int i=0;i<N;i++){
            cin >> arr[i];
        }
        maxsum[N-1] = sum[N-1] = arr[N-1];
        maxsum[N-2] = sum[N-2] = arr[N-1]+arr[N-2];
        maxsum[N-3] = sum[N-3] = arr[N-1]+arr[N-2]+arr[N-3];
        for(int i=N-4;i>=0;i--){
            sum[i] = sum[i+1]+arr[i];
            long long int A = arr[i]+(sum[i+1]-maxsum[i+1]);
            long long int B = arr[i]+arr[i+1]+(sum[i+2]-maxsum[i+2]);
            long long int C = arr[i]+arr[i+1]+arr[i+2]+(sum[i+3]-maxsum[i+3]);
            long long int tmp = A>B?A:B;
            maxsum[i] = tmp>C?tmp:C;
        }
        cout << maxsum[0] << endl;
    }
    return 0;        
}
