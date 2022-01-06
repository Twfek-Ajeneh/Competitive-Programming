#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (int)1e9

struct DSU{
    vector<int> par, siz;
    int comp;

    DSU(int n) {
        par.assign(n, 0);
        siz.assign(n, 1);
        iota(par.begin(), par.end(), 0);
        comp=n;
    }

    int find(int x) {
        while(x!=par[x]) par[x]=par[par[x]], x=par[x];
        return x;
    }
    
    void merge(int u, int v) {
        int a=find(u);
        int b=find(v);
        if(a==b) return;
        comp--;
        if(siz[a]>siz[b]) swap(a, b);
        siz[b]+=siz[a];
        siz[a]=0;
        par[a]=par[b];
    }     
};