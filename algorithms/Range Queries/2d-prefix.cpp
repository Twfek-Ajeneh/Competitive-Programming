#include <bits/stdc++.h>
#define ll long long
#define inf (int)1e9
using namespace std;

//2D-Prefix sum:
vector<vector<int>> prefix2d(1100 , vector<int>(1100 , 0)), 
                    a(1100 , vector<int> (1100 , 0));

//a & prefix arrays start from 1 to n and from 1 to m
void generate_prefix(int n , int m){
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            prefix2d[i][j] = a[i][j] + prefix2d[i-1][j] + 
                            prefix2d[i][j-1] - prefix2d[i-1][j-1];
}

//get prefix for square between two points (inclusive)
int get_prefix(int x1 , int y1 , int x2 , int y2){
    return (prefix2d[x2][y2] - prefix2d[x2][y1-1] 
                - prefix2d[x1-1][y2] + prefix2d[x1-1][y1-1]);
}


//2D-Prefix (Min / Max):
vector<vector<int>> prefix2d(1100 , vector<int>(1100 , inf)), 
                    a(1100 , vector<int> (1100 , 0));

//a & prefix arrays start from 1 to n and from 1 to m
//change the (min / max) and the value in prefix array
void generate_prefix(int n , int m){
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            prefix2d[i][j] = min({a[i][j] , prefix2d[i-1][j] , prefix2d[i][j-1]}); 
}

//get prefix for square from point to (1 , 1) (inclusive)
int get_prefix(int x , int y){
    return prefix2d[x][y];
}


//2D-Prefix GCD:
vector<vector<int>> prefix2d(1100 , vector<int>(1100 , 0)), 
                    a(1100 , vector<int> (1100 , 0));

//a & prefix arrays start from 1 to n and from 1 to m
void generate_prefix(int n , int m){
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            prefix2d[i][j] = __gcd( a[i][j] ,  
                                    __gcd(prefix2d[i-1][j], prefix2d[i][j-1])); 
}

//get prefix for square from the point to (1 , 1) (inclusive)
int get_prefix(int x , int y){
    return prefix2d[x][y];
}


//Find the (min / max) value for each continuous subArray of size k:

//1D-Array
vector<int> get_window_1d(const vector<int> &a, int k)
{
    const int n = a.size();
    vector<int> b(n - k + 1);
    deque<int> mono;
    for (int i = 0; i < n; ++i)
    {
        //change this condition to >= for (min / max)
        while (!mono.empty() && a[mono.back()] <= a[i]) 
            mono.pop_back();

        mono.push_back(i);

        if (mono.front() <= i - k) mono.pop_front();

        if (i + 1 >= k) b[i + 1 - k] = a[mono.front()];
    }
    return b;
}

//2D-matrix Find the (min / max) value for each continuous subMatrix of size k × l:
vector<vector<int>> get_window_2d(const vector<vector<int>> &a, int k, int l)
{
    //change the condition in the 1d function to change it here
    const int n = a.size(), m = a[0].size();
    vector<vector<int>> b(m - l + 1, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        const auto tmp = get_window_1d(a[i], l);
        for (int j = 0; j < m - l + 1; ++j)
        {
            b[j][i] = tmp[j];
        }
    }
    vector<vector<int>> c(n - k + 1, vector<int>(m - l + 1));
    for (int j = 0; j < m - l + 1; ++j)
    {
        const auto tmp = get_window_1d(b[j], k);
        for (int i = 0; i < n - k + 1; ++i)
        {
            c[i][j] = tmp[i];
        }
    }
    return c;
}