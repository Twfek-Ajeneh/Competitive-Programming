#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (int)1e9

//Z-Function:
vector<int> z(100100);
string s;

void z_function() {
    int n = s.size();
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
}

// Z-Function Application:
// 1. find and display the positions of all occurrences of the string  s in the string t by s+#+t;

// 2. Number of distinct substrings in a string in O(n^2):
// we add character  of string one by one in each adding operation we reverse the string
// and recalculate the z-function of it the new number of distinct substring will be length(t) - z_max
// the sum of each operation will be the number of distinct substring in s

// 3. String compression:
// compute the Z-function of  s 
// loop through all i such that i divides n 
// Stop at the first i such that i + z[i] = n 
// Then, the string s can be compressed to the length i