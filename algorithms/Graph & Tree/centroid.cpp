#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (int)1e9

/// center of the tree is : The node in the middle of the largest path in the tree.
/// centroid of the tree is : equivalent to its center of mass.

//Centroid of tree:
vector<int> adj[100100] , subtree(100100);
int n;

int dfs(int u, int p) {
    for (auto v : adj[u]){
        if (v != p) 
            subtree[u] += dfs(v, u);
    }

    return subtree[u] + 1;
}

int centroid(int u, int p) {
    for (auto v : adj[u]){
        if (v != p && subtree[v] > n/2) 
            return centroid(v, u);
    }

    return u;
}


//Centroid Decomposition:
//one based indexed
struct CentroidDecomposition {
	vector<vector<int>> adj;
	vector<int> par , subtree , visited;

	CentroidDecomposition(vector<vector<int>> &adj) : adj(adj) {
		int n = adj.size()+1;
		par.resize(n);
		subtree.resize(n);
        visited.resize(n);
		build(1, -1);
	}

	void build(int u, int p) {
		int n = treeSize(u, p);
		int centroid = getCentroid(u, p, n);
		par[centroid] = p;
        visited[centroid] = 1;

		for (auto v : adj[centroid]){
            if(!visited[v])
                build(v, centroid);
        }
	}

	int treeSize(int u, int p) {
        subtree[u] = 1;

		for (auto v : adj[u]){
			if (v != p && !visited[v]) 
                subtree[u] += treeSize(v, u);
        }

		return subtree[u];
	}

	int getCentroid(int u, int p, int n) {
		for (auto v : adj[u]){
			if (v != p && subtree[v] > n/2 && !visited[v]) 
                return getCentroid(v, u, n);
        }

		return u;
	}
};