#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Divisors of number n:
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

//Count the number of numbers divisible by M in range [A - B]:
ll countDivisible(ll A, ll B, ll M)
{
    if (A % M == 0)
        return (B / M) - (A / M) + 1;
    return (B / M) - (A / M);
}