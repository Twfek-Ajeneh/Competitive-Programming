#include <bits/stdc++.h>
using namespace std;
#define ll long long

// to build and answer the query:
vector<vector<int>> st(20 , vector<int> (100100));
vector<int> a(100100);
int n;

void build(){
    for(int i = 0 ; i < n ; i++) st[0][i] = a[i]; // to change
    for(int j = 1 ; 1<<j <= n ; j++)
        for(int i = 0 ; i+(1<<j) <= n ; i++)
            st[j][i] = temp (st[j-1][i] , st[j-1][i+(1<<j-1)]); // to change
}

int inline get (int l , int r){
    int k = log2(r-l+1);
    return temp (st[k][l] , st[k][r-(1<<k)+1]);  //to change
}


// to build and answer range sum queries with complexity log2(n) :

vector<vector<int>> st(20 , vector<int> (100100));

void build(){
    for(int i = 0 ; i < n ; i++) st[0][i] = a[i];
    for (int j = 1 ; 1<<j <= n ; j++)
        for(int i = 0 ; i+(1<<j) <= n ; i++)
            st[j][i] = st[j-1][i] + st[j-1][i+(1<<j-1)];
}

ll inline get (int l , int r){
    ll sum = 0;
    for(int j = 20 ; j >= 0 ; j--){
        if((1<<j) <= r-l+1){
            sum += st[j][l];
            l += 1<<j;
        }
    }
    return sum;
}