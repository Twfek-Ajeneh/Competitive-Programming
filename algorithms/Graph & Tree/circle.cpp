#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (int)1e9

//Find circle in graph (Undirected):
vector<int> visited(100100) , parent(100100) , adj[100100];
int startCircle = 0 , endCircle = 0;

bool findCircle(int u , int par){ // node and parent
    visited[u] = true;
    for(auto v : adj[u]){
        if(v==par) continue;
        if(visited[v]){
            endCircle = u;
            startCircle = v;
            return true;
        }
        parent[v] = u;
        if(findCircle(v , parent[v])) return true;
    }
    return false;
}

void printCircle(int node = endCircle){
    if(node==startCircle){
        cout<<node<<" ";
        return ;
    }
    printCircle(parent[node]);
    cout<<node<<" ";
}

//Find circle in graph (directed):
vector<int> visited1(100100) , visited2(100100) , parent(100100) , adj[100100];
int startCircle = 0 , endCircle = 0;

bool findCircle(int u){
    visited1[u] = true;
    visited2[u] = true;
    for(auto v : adj[u]){
        if(visited2[v]){
            endCircle = u;
            startCircle = v;
            return true;
        }
        parent[v] = u;
        if(!visited1[v] && findCircle(v)) return true;
    }
    visited2[u] = false;
    return false;
}

void printCircle(int node = endCircle){
    if(node==startCircle){
        cout<<node<<" ";
        return ;
    }
    printCircle(parent[node]);
    cout<<node<<" ";
}