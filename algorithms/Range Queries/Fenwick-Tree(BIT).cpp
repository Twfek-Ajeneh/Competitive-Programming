#include <bits/stdc++.h>
using namespace std;
#define ll long long

// to answer point update and range query
//           range update and point query:

struct FenwickTree {
    vector<int> bit;
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    int query(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r]; // to change
        return ret;
    }

    int query(int l, int r) {
        return query(r) - query(l - 1);
    }

    void update(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta; //to change
    }
    
    void update(int l, int r, int val) {
        update(l, val);
        update(r + 1, -val);
    }
};


// to answer point update and 2d array query:

struct FenwickTree2D {
    vector<vector<int>> bit;
    int n , m;

    FenwickTree2D(int n , int m) {
        this->n = n;
        this->m = m;
        bit.assign(n , vector<int>(m , 0));
    }

    FenwickTree2D(vector<vector<int>> a , int n , int m) : FenwickTree2D(n , m) {
        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < m; j++)
                update(i , j , a[i][j]);
    }

    int query(int x, int y) {
        int ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }

    void update(int x, int y, int delta) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;
    }
};