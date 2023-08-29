#include <bits/stdc++.h>
using namespace std;

//Sieve function:
vector<int> isPrime(1000001); //can be 1e7

void sieve(){
    for(int i = 1 ; i <= 1000000 ; i++)
        isPrime[i] = 1;
    isPrime[1] = 0;
    for(int i = 1 ; i <= 1000 ; i++){
        if(isPrime[i]==1){
            for(int j = i*i ; j <= 1000000 ; j+=i)
                isPrime[j] = 0;
        }
    }
}

//Checking primes using sieve:
vector<bool> is_prime(1000001, true);

void sieveToN(int n){
    is_prime[1] = false;
    for(int i=2 ; i<n ; i++)
        if(is_prime[i])
            for(int j=i+i ; j<n ; j+=i)
                is_prime[j]=false;
}

//Check if number prime or not:
bool checkPrime(int n){
    bool isPrime = true;
    for(int i = 2 ; i*i <= n ; i++){
        if(n%i==0){
            isPrime = false ;
            break;
        }
    }
    return isPrime;
}

//Factoring of number:
vector <int> primes;

void factoringNumber(int n){
    while(n%2==0) n/=2 , primes.push_back(2);
    for(int i = 3 ; i*i <= n ; i+=2){
        while(n%i==0){
            n/=i;
            primes.push_back(i);
        }
    }
    if(n!=1) primes.push_back(n);
}

//Factoring of number in O(log(x)):
const int N = 1e7 + 7;
int firstFa[N] , lastFa[N];

vector<int> factorization(int x){
    vector<int> ret;
    while(x!=1){
        ret.push_back(firstFa[x]);
        x/=firstFa[x];
    }
    return ret;
}

// call this function in main then use factorization
void sieve(){
    for (int i = 0; i < N; i++)
        firstFa[i] = lastFa[i] = i;
    for (int i = 2; i < N; i++)
    {
        if(firstFa[i] == i){
            for (int j = i+i; j < N; j+=i)
            {
                if(firstFa[j]==j)
                    firstFa[j] = i;
                lastFa[j] = i;
            }
        }
    }
}


// Miller-Rabin primality test:
using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n) {
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}
