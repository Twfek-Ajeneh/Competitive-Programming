#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9+7)
#define ll long long

//Useful define:
#define pi 3.14159265358979323846
#define outf(x) printf("%.15f\n" , x)
#define outf(x) cout<<fixed<<setprecision(15)<<x<<endl

//Calculate combination for small constraint:
ll ncr(int n,int r)  
{
    ll fac1 = 1 , fac2 = 1 , fac;
    for (int i = r; i >= 1; i-- , n--)
    {
        fac1 = fac1 * n;
        if(fac1%i==0)
            fac1 = fac1 / i;
        else
            fac2 = fac2 * i;
    }
    fac = fac1 / fac2;
    return fac % MOD;
} 

//Fast power and CNR:
const int N = 300500;
const int mod = 1000000007;
ll fact[N] , invFact[N];

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
    if(n==k) return 1;
    if (k > n) {
        return 0;
    }
    return (fact[n] * invFact[k] % mod * invFact[n - k] % mod)%mod;
}

//call it first in main
void init(){ 
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        invFact[i] = fast_pow(fact[i], mod - 2);
    }
}

//Calculate the value of (x^n)%m :
int modPow(int x, int n, int m) {
    if (n == 0) return 1 % m;
    ll u = modPow(x , n/2 , m);
    u = (u * u) % m;
    if (n%2 == 1) u = (u * x) % m;
    return u;
}

//Operation functions with mod:
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
// note: 3/5 % MOD =>> 3*inv(5 , MOD)
// note: mul(prefix[i] , inv(prefix[i-1] , MOD) , MOD)


//Operation function with mod:
//this function faster then the other
void add_self(int& x, int y)
{
    if((x += y) >= MOD) x -= MOD;
}
int add(int x, int y)
{
    return add_self(x, y), x;
}
void sub_self(int& x, int y)
{
    if((x -= y) < 0)    x += MOD;
}
int sub(int x, int y)
{
    return sub_self(x, y), x;
}
int mul(int x, int y)
{
    return (long long) x * y % MOD;
}


//combinatric rule:

// 1.power of two sum: 1^2 + 2^2 + 3^2 + 4^2 + 5^2 + ... + n^2 = (n(n+1)((2*n)+1))/6