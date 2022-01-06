#include <bits/stdc++.h>
using namespace std;

// sieve function:
vector<int> isprime(1000001);

void sieve(){
    for(int i = 1 ; i <= 1000000 ; i++)
        isprime[i] = 1;
    isprime[1] = 0;
    for(int i = 1 ; i <= 1000 ; i++){
        if(isprime[i]==1){
            for(int j = i*i ; j <= 1000000 ; j+=i)
                isprime[j] = 0;
        }
    }
}


// check if number prime or not:

bool isPrime(int n){
    bool isprime = true;
    for(int i = 2 ; i*i <= n ; i++){
        if(n%i==0){
            isprime = false ;
            break;
        }
    }
    return isprime;
}


// Factoring of number:
vector <int> prime;

void factoringNumber(int n){
    for(int i = 2 ; i*i <= n ; i++){
        while(n%i==0){
            n/=i;
            prime.push_back(i);
        }
    }
    if(n!=1) prime.push_back(n);
}


// Checking primes using sieve:
vector<bool> is_prime(1000001, true);

void sieveToN(int n){
    for(int i=2 ; i<n ; i++)
        if(is_prime[i])
            for(int j=i+i ; j<n ; j+=i)
                is_prime[j]=false;
}