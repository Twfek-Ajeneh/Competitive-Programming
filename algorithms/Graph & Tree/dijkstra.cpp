#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (int)1e9
#define node tuple<int , int>

//Dijkstra:
vector<int> D(100100 , inf);
vector<pair<int , int>> adj[100100];

void dijkstra (int src){
    priority_queue <node , vector<node> , greater<node>> q; 
    D[src] = 0;
    q.push({0 , src});
    while(!q.empty()){
        auto [d ,u] = q.top();
        q.pop();
        if(d > D[u]) continue;
        for(auto[v , w] : adj[u]){
            if(D[v] > D[u]+w){
                // parent[v] = u; // if you need to print path
                D[v] = D[u]+w;
                q.push({D[v] , v});
            }
        }
    }
}

// to print the path:
vector<int> parent(100100 , -1);

void printPath(int j){
    if (parent[j] == - 1){
        cout<<j<<" ";
        return;
    }
    printPath(parent[j]);
    cout<<j<<" ";
}