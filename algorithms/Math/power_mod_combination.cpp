#include <bits/stdc++.h>
using namespace std;
#define ll long long


// calculate combination (توافيق):
const long int a = 1000000000;

long long int ncr(int n,int r)  
{
    long long int fac1 = 1,fac2=1,fac;
    for(int i=r;i>=1;i--,n--)
    {
        fac1 = fac1 * n;
        if(fac1%i==0)
            fac1 = fac1/i;
        else
            fac2 = fac2 * i;
    }
    fac = fac1/fac2;
    return fac%a;
} 


// to calculate the value of (x^n)%m :

int modpow(int x, int n, int m) {
    if (n == 0) return 1%m;
    long long u = modpow(x,n/2,m);
    u = (u*u)%m;
    if (n%2 == 1) u = (u*x)%m;
    return u;
}


// fast power and CNR:
const int N = 300500;
const int mod = 1000000007;
ll fact[N];
ll invFact[N];


//in start of main
// for (int i = 1; i < N; i++) {
//     fact[i] = (fact[i - 1] * i) % mod;
//     invFact[i] = fast_pow(fact[i], mod - 2);
// }

ll fast_pow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p % 2 == 0) {
            a = (a * a) % mod;
            p /= 2;
        } else {
            res = (res * a) % mod;
            p--;
        }
    }
    return res;
}

ll C(int n, int k) {
    if (k > n) {
        return 0;
    }
    return (fact[n] * invFact[k] % mod * invFact[n - k] % mod)%mod;
}


//functions:
int mul(int x , int y , int m)
{
    return (ll) x*y % m;
}
int sum(int x , int y , int m)
{
    return (x+y) % m;
}
int sub(int x , int y , int m)
{
    return sum((x-y)%m , m , m);
}
int po(int x , int y , int m)
{
    if(!y) return 1;
    if(y&1) return mul(x , po(x,y-1,m) , m);
    int z = po(x , y/2 , m);
    return mul(z , z , m);
}
int inv(int x , int m)
{
    return po(x , m-2 , m);
}