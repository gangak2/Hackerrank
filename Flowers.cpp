/*
You and your K-1 friends want to buy N flowers. Flower number i has cost ci. Unfortunately 
the seller does not like a customer to buy a lot of flowers, so he tries to change the price 
of flowers for customer who had bought flowers before. More precisely if a customer has 
already bought x flowers, he should pay (x+1)*ci dollars to buy flower number i.
You and your K-1 friends want to buy all N flowers in such a way that you spend the least 
amount of money possible. You can buy the flowers in any order.

Input:

The first line of input contains two integers N and K (K <= N) next line contains N positive 
integers c1,c2,…,cN respectively.

Output:

Print the minimum amount of money you (and your friends) have to pay in order to buy all N 
flowers.

Sample input :

3 3
2 5 6

Sample output :

13

Explanation :
In the example each of you and your friends should buy one flower. in this case you have to 
pay 13 dollars.

Constraint :

1 <= N, K  <= 100
Each ci is not more than 1,000,000
*/

#include<iostream>
#include<algorithm>
using namespace std;
int main(void){

 

//Helpers for input and output

   int N, K;
   cin >> N >> K;
   vector<int> C;
    int temp;
   for(int i = 0; i < N; i++){
      cin >> temp;
      C.push_back(temp);
   }
   sort(C.begin(),C.end());
    
   long long int result=0;
    for(int i=0;i<N;i++){
        result+=((i/K + 1)*C[N-i-1]);
    }
   cout << result << "\n";
   
   return 0;
}