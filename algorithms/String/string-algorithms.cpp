#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Longest common subsequence O(2^(x+y)):
int lcSubSequence(string X , string Y , int xSize , int ySize){
    // subsequence: ahmad -> amd
    if(xSize==0 || ySize==0) 
        return 0;
    if(X[xSize-1]==Y[ySize-1])
        return 1 + lcSubSequence(X , Y , xSize-1 , ySize-1);
    else 
        return max(lcSubSequence(X , Y , xSize , ySize-1) , lcSubSequence(X , Y , xSize-1 , ySize));
}

//Longest common substring O(n*n):
int lcSubString(string X , string Y){
    int xSize = X.size() , ySize = Y.size();
    int lc[xSize+1][ySize+1];
    int result = 0;

    for(int i=0; i<=xSize; i++){
        for(int j=0; j<=ySize; j++){
            if(i==0 || j==0)
                lc[i][j] = 0;
            else if(X[i-1]==Y[j-1]){
                lc[i][j] = 1 + lc[i-1][j-1];
                result = max(result , lc[i][j]);
            }
            else
                lc[i][j] = 0;
        }
    }

    return result;
}


// Minimal Rotation:
// the lexicographically minimal rotation of a string
// the rotation is shift left
// acab -> caba -> abac -> baca
int minimal_rotation(string s) {
    int n = s.length();
    vector<int> f(2 * n, -1);
    int k = 0;
    for (int j = 1; j < 2 * n; j++) {
        int i = f[j - k - 1];
        while (i != -1 && s[j % n] != s[(k + i + 1) % n]) {
            if (s[j % n] < s[(k + i + 1) % n]) {
                k = j - i - 1;
            }
            i = f[i];
        }
        if (i == -1 && s[j % n] != s[(k + i + 1) % n]) {
            if (s[j % n] < s[(k + i + 1) % n]) {
                k = j;
            }
            f[j - k] = -1;
        } else {
            f[j - k] = i + 1;
        }
    }
    return k;
}


//Longest Regular Bracket substring in string in O(n):
string s;
int dp[1000100]; //fill with zero

int LRBSubstring(){
    int ans = 0;
    for (int i = 1; i < s.size(); i++)
    {
        if(s[i]==')'){
            if(s[i-1]=='(') 
                dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
            else if(i-dp[i-1] > 0 && s[i-dp[i-1]-1]=='(')
                dp[i] = dp[i-1] + (i-dp[i-1] >= 2 ? dp[i - dp[i-1] - 2] : 0) + 2;
            ans = max(ans , dp[i]);
        }
    }
    return ans;
}


//All Substring Longest Common Subsequence:
//get LCS of s with all substring of t
const int N = 2002;
int f[N][N], g[N][N];

void sub_String_LCA(string s , string t){
    int  n = s.size(), m = t.size();
    s = "#" + s;
    t = "#" + t;
    for (int i = 1; i <= m; ++i) f[0][i] = i;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i] == t[j]) {
                f[i][j] = g[i][j - 1];
                g[i][j] = f[i - 1][j];
            } 
            else {
                f[i][j] = max(f[i - 1][j], g[i][j - 1]);
                g[i][j] = min(g[i][j - 1], f[i - 1][j]);
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = i, ans = 0; j <= m; ++j) {
            if (i > f[n][j]) ++ans;
            cout << ans << ' '; //LCS of s and t[i, j]
        }
        cout << '\n';
    }
}