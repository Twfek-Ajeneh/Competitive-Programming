#include <bits/stdc++.h>
using namespace std;
#define ll long long

// to find the depth of each node:
vector<int> depth(100100) , adj[100100];

void treeDepth(int u , int parent , int d){
    depth[u] = d;
    for(auto v : adj[u])
        if(v!=parent)
            treeDepth(v , u , d+1);
}


// to find the size of each subtree:
vector<int> subtree(100100);

int treeSize(int u , int parent){
    subtree[u] = 1;
    for(auto v : adj[u])
        if(v!=parent){
            int s = treeSize(v , u);
            subtree[u]+=s;
        }
    return subtree[u];
}


// to find th diameter of the tree:
int diameter = 0 ;

int treeDiameter(int u , int parent){
    int mx1 = 0;
    int mx2 = 0;
    for(auto v : adj[u]){
        if(v!=parent){
            int h = treeDiameter(v , u)+1;
            if(h > mx2) mx2 = h;
            if(mx2 > mx1) swap(mx1 , mx2);
        }
    }
    diameter = max(diameter , mx1+mx2);
    return mx1;
}