#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (int)1e9

vector<vector<int>> prefix2d(1100 , vector<int>(1100)) , a(1000 , vector<int> (1000));

void generate_prefix(int n , int m){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            prefix2d[i][j] = a[i][j] + prefix2d[i-1][j] + 
                            prefix2d[i][j-1] - prefix2d[i-1][j-1];
}

int get_prefix(int x1 , int y1 , int x2 , int y2){
    return (prefix2d[x2][y2] - prefix2d[x2][y1-1] - prefix2d[x1-1][y2] + prefix2d[x1-1][y1-1]);
}