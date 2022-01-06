#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> dist(1000 , vector<int> (1000));

void floyd(){
    for(int k = 1 ; k <= 100 ; k++) //check n
        for(int i = 1 ; i <= 100 ; i++) //check n
            for(int j = 1 ; j <=100 ; j++) //check n
                dist[i][j] = min(dist[i][j] , dist[i][k]+dist[k][j]);
}