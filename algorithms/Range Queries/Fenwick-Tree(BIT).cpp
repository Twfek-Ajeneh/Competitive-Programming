#include <bits/stdc++.h>
#define ll long long
#define inf (int)1e9
#define inf18 1e18
using namespace std;


//FenwickTree (BIT) sum query on 1D-Array:

// answer point update and range query
struct FenwickTreeSum {
    vector<int> bit;
    int n;

    FenwickTreeSum(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    //build in O(n)
    FenwickTreeSum(vector<int> a) : FenwickTreeSum(a.size()) {
        for (int i = 0; i < n; i++) {
            bit[i] += a[i];
            int r = i | (i + 1);
            if (r < n) bit[r] += bit[i];
        }
    }

    int query(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r]; // to change
        return ret;
    }

    // for all query
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }

    void update(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta; //to change
    }
};


//FenwickTree (BIT) sum query on 1D-Array (range update-query):

//answer range update and range query
struct FenwickTreeSum{
    int n;
    vector<ll> M , A;

    FenwickTreeSum(int n){
        this->n = n;
        M.assign(n , 0);
        A.assign(n , 0);
    }

    FenwickTreeSum(vector<ll> &a) : FenwickTreeSum(a.size()) {
        for (int i = 0; i < a.size(); i++){
            update(i , i , a[i]);
        }
    }

    void upd(int i, ll mul, ll add){
        while (i < n){
            M[i] += mul;
            A[i] += add;
            i |= (i + 1);
        }
    }

    void update(int l, int r, ll x){
        upd(l, x, -x * (l - 1));
        upd(r, -x, x * r);
    }

    ll query(int i){
        ll mul = 0, add = 0;
        ll st = i;
        while (i >= 0) {
            mul += M[i];
            add += A[i];
            i = (i & (i + 1)) - 1;
        }
        return (mul * st + add);
    }

    ll query(int l, int r){
        return query(r) - query(l - 1);
    }
};


//FenwickTree (BIT) (min \ max) query on 1D-Array:

//point update and [0 - r] range query
struct FenwickTreeMin {
    vector<int> bit;
    int n;

    FenwickTreeMin(int n) {
        this->n = n;
        bit.assign(n, inf);
    }

    FenwickTreeMin(vector<int> a) : FenwickTreeMin(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    int get(int r) {
        int ret = inf;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = min(ret, bit[r]);
        return ret;
    }

    void update(int idx, int val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = min(bit[idx], val);
    }
};


//FenwickTree (BIT) sum query on 2D-Array:

//point update
struct FenwickTree2D {
    vector<vector<int>> bit;
    int n , m;

    FenwickTree2D(int n , int m) {
        this->n = n;
        this->m = m;
        bit.assign(n , vector<int>(m , 0));
    }

    FenwickTree2D(vector<vector<int>> &a , int n , int m) : FenwickTree2D(n , m) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                update(i , j , a[i][j]);
    }

    //answer query from (x , y) to (0 , 0)
    int query(int x, int y) {
        int ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }

    //answer query from (x2 , y2) to (x1 , y2)
    int query(int x1 , int y1 , int x2 , int y2){
        return query(x2 , y2) - query(x1-1 , y2)
                - query(x2 , y1-1) + query(x1-1 , y1-1);
    }

    void update(int x, int y, int delta) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;
    }
};


//FenwickTree (BIT) sum query on 2D-Array:
//range-update and range-query //One-based indexing
struct FenwickTree2D{
    vector<vector<vector<ll>>> M , A;
    const int n , m;

    FenwickTree2D(int n , int m) : n(n) , m(m) {
        M.assign(n, vector<vector<ll>>(m , vector<ll>(2 , 0)));
        A.assign(n, vector<vector<ll>>(m , vector<ll>(2 , 0)));
    }

    FenwickTree2D(vector<vector<ll>> a) : FenwickTree2D(a.size() , a[0].size()){
        for (int i = 1; i < a.size(); i++)
            for (int j = 1; j < a[0].size(); j++)
                update(i , j , i , j , a[i][j]);
    }

    void upd2(vector<vector<vector<ll>>> &t, int x, int y, ll mul, ll add){
        for (int i = x; i < n; i += i & -i){
            for (int j = y; j < m; j += j & -j){
                t[i][j][0] += mul;
                t[i][j][1] += add;
            }
        }
    }

    void upd1(int x, int y1, int y2, ll mul, ll add){
        upd2(M, x, y1, mul, -mul * (y1 - 1));
        upd2(M, x, y2, -mul, mul * y2);
        upd2(A, x, y1, add, -add * (y1 - 1));
        upd2(A, x, y2, -add, add * y2);
    }

    void update(int x1, int y1, int x2, int y2, ll val){
        upd1(x1, y1, y2, val, -val * (x1 - 1));
        upd1(x2, y1, y2, -val, val * x2);
    }

    ll query2(vector<vector<vector<ll>>> &t , int x, int y){
        ll mul = 0, add = 0;
        for (int i = y; i > 0; i -= i & -i){
            mul += t[x][i][0];
            add += t[x][i][1];
        }
        return mul * y + add;
    }

    ll query1(int x, int y){
        ll mul = 0, add = 0;
        for (int i = x; i > 0; i -= i & -i){
            mul += query2(M, i, y);
            add += query2(A, i, y);
        }
        return mul * x + add;
    }

    ll query(int x1, int y1, int x2, int y2){
        return query1(x2, y2)-query1(x1-1, y2)-query1(x2, y1-1)+query1(x1-1, y1-1);
    }
};