#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define left p<<1 , l , (l+r)>>1
#define right p<<1|1 , ((l+r)>>1)+1 , r

// in complexity O(n) for each query:
vector<int> depth(100100) , parent(100100);

int solve(int x , int y){
    while(depth[x] > depth[y]){
        x = parent[x];
    }
    while(depth[x] < depth[y]){
        y = parent[y];
    }
    while(x!=y){
        x = parent[x];
        y = parent[y];
    }
    return x;
}


// in complexity => O(log(n)):

// by segment tree:

struct LCA{
    vector<int> first , occur , depth , seg;
    vector<vector<int>> adj;

    LCA(vector<vector<int>> adj , int n , int root){
        this->adj = adj;
        depth.assign(n+1 , 0);
        first.assign(n+1 , 0);
        occur.reserve(n*2);
        dfs(root , 0);
        seg.assign((occur.size()*4)+100 , 0);
        build(1 , 0 , occur.size()-1);
    }

    void dfs(int u , int parent , int d = 0){
        depth[u] = d; 
        first[u] = occur.size();
        occur.push_back(u);
        for(auto v : adj[u])
            if(v!=parent){
                dfs(v , u , d+1);
                occur.push_back(u);
            }
    }

    int build(int p , int l , int r){
        if(l==r) return seg[p] = occur[l];
        int c1 = build(left) , c2 = build(right);
        if(depth[c1] < depth[c2]) seg[p] = c1; else seg[p] = c2;
        return seg[p];
    }
    
    int query(int u , int v){
        int l = first[u] , r = first[v];
        if(l > r) swap(l , r);
        return query(l , r , 1 , 0 , occur.size()-1);
    }

    int query (int i , int j , int p , int l , int r){
        if(j<l  ||  r<i) return -1;
        if(i<=l && r<=j) return seg[p];
        int c1 = query(i , j , left) , c2 = query(i , j , right);
        if(c1==-1) return c2; if(c2==-1) return c1;
        return depth[c1] < depth[c2] ? c1 : c2;
    }
};


// by sparse table:

struct LCA{
    vector<int> first , occur , depth;
    vector<vector<int>> st , adj;

    LCA(vector<vector<int>> adj , int n , int root){
        this->adj = adj;
        depth.assign(n+1 , 0);
        first.assign(n+1 , 0);
        occur.reserve(n*2);
        dfs(root , 0);
        st.assign(log2(occur.size())+5 , vector<int> (occur.size()+100));
        build(occur.size());
    }

    void dfs(int u , int parent , int d = 0){
        depth[u] = d; 
        first[u] = occur.size();
        occur.push_back(u);
        for(auto v : adj[u])
            if(v!=parent){
                dfs(v , u , d+1);
                occur.push_back(u);
            }
    }

    void build(int n){
        for(int i = 0 ; i < n ; i++) st[0][i] = occur[i];
        for(int j = 1 ; 1<<j <= n ; j++)
            for(int i = 0 ; i+(1<<j) <= n ; i++){
                int c1 = st[j-1][i] , c2 = st[j-1][i+(1<<j-1)];
                if(depth[c1] <= depth[c2]) st[j][i] = c1;
                else st[j][i] = c2;
            }
    }

    int inline get (int l , int r){
        l = first[l]; r = first[r];
        if(l > r) swap(l , r);
        int k = log2(r-l+1);
        int c1 = st[k][l] , c2 = st[k][r-(1<<k)+1];
        return (depth[c1] <= depth[c2]) ? c1 : c2;
    }
};


// LCA by Binary Lifting:

////!!!!!!first node is 0 here
struct LCA
{
    int n, lg;
    vector<int> lev;
    vector<vector<int>> par , adj;
    
    LCA(vector<vector<int>> adj , int n , int root){
        this->adj = adj;
        this->n = n;
        this->lg = log2(n);
        lev.assign(n , 0);
        par.assign(n, vector<int>(lg + 1, -1));
        dfs(root, root, 0);
    }

    void dfs(int u, int p, int d){
        lev[u] = d; par[u][0] = p;
        for (int j = 1; 1 << j < n; j++)
            if (par[u][j - 1] != -1)
                par[u][j] = par[par[u][j - 1]][j - 1];
        for (auto v : adj[u])
            if (v != p)
                dfs(v, u, d + 1);
    }

    int get(int u, int v)
    {
        if (lev[u] < lev[v])
            swap(u, v);
        int diff = lev[u] - lev[v];
        for (int i = lg; i >= 0; i--)
            if (diff & 1 << i)
                u = par[u][i];
        if (u == v)
            return u;
        for (int i = lg; i >= 0; i--)
            if (par[u][i] != -1 && par[u][i] != par[v][i])
                u = par[u][i], v = par[v][i];
        return par[u][0];
    }
};


// by using DSU:

// code of DSU
// don not forget to fill the query array;

// vector<vector<int>> adj , query;
// vector<int> visited , ancestor;

// void dfs(int u){
//     visited[u] = 1; ancestor[u]  = u;
//     for(auto v : adj[u]){
//         if(!visited[v]){
//             dfs(v);
//             g.merge(u , v); //DSU object
//             ancestor[g.find(u)] = u;
//         }
//     }
//     for(auto i : query[u]){
//         if(visited[i])
//             cout<<ancestor[g.find(i)]<<endl;
//     }
// }

// void LCA(){
//     ancestor.assign(n+1);
//     visited.assign(n+1 , 0);
//     dfs(root);
// }