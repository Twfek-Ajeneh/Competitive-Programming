#include <bits/stdc++.h>
using namespace std;

// Divisors of number :
set<int> divisors;

void getDivisors(int n){
    for (int i = 1 ; i*i <= n ; i++){
        if(n%i==0){
            int x = n/i;
            divisors.insert(i);
            if(x!=i) divisors.insert(x);
        }
    }
}


//Divisors using sieve for 1->n number:
vector<vector<int>> allDivisors;

void getDivisorsToN(int n){
    for(int i=1 ; i<n ; i++)
        for(int j=i ; j<n ; j+=i)
            allDivisors[j].push_back(i);
}