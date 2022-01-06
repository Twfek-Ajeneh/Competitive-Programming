#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (int)1e9

set<int> circle;
vector<int> visited , adj[100100];
int g = inf , target = inf;

void find_circle(int u , int p){
    visited[u] = 1;
    for(auto v : adj[u]){
        if(!visited[v]){
            find_circle(v , u);
            if(u==target){
                g = inf;target = inf;
                circle.insert(u);
                return;
            }
            if(g==1){
                circle.insert(u);
                return;
            }
        }
        else if(visited[v]==1 && v!=p){
            g = 1;target = v;
            circle.insert(u);
            return;
        }
    }
    visited[u] = 2;
}