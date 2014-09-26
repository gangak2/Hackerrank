#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    long long int Height[61];
    Height[0]=1;
    for(int i=1;i<61;i++){
        if(i%2 == 1){
            Height[i] = 2*Height[i-1];
        }
        else if(i%2 == 0){
            Height[i] = 1+Height[i-1];
        }
    }
    while (T--) {
        int n;
        cin >> n;
        cout << Height[n] << endl;
    }
}
