#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<long long int> StrangeNumbers;

int find(long long int K){
	for(int i=0;i<StrangeNumbers.size();i++){
		if(StrangeNumbers[i] < K)	continue;
		else return i;
	}
	return StrangeNumbers.size();
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	for(int i=0;i<10;i++){
		StrangeNumbers.push_back(i);
	}
	long long int decile = 10;
	int dec = 2;
	while(dec < 19){
		for(int i = find(decile/dec);StrangeNumbers[i]*dec < 10*decile;i++){
			StrangeNumbers.push_back(StrangeNumbers[i]*dec);
		}
		dec++;
		decile*=10;
	}
	
	int T;
	cin >> T;
	while(T--){
		long long int start,end;
		int add = 0;
		cin >> start >> end;
		int k_s = find(start);
		int k_e = find(end);
		if(StrangeNumbers[k_e] == end)	add=1;
		cout << k_e - k_s + add << endl;
	}
    return 0;
}
