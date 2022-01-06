#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (int)1e9

vector<int> D(100100 , inf) , adj[100100];

void bfs(int src){
    queue <int> q;
    q.push(src);
    D[src] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u])
            if(D[v] == inf){
                D[v] = D[u]+1;
                q.push(v);
            }
    }
}