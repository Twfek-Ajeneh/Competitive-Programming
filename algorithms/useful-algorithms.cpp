#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (int)1e9
#define inf18 1e18

//Maximum subArray sum:
int n;
vector<ll> a(100100);

int maxSubArray(){
    ll last = -inf18 , ans = -inf18;
    for(int i = 0; i < n; i++){
        last = max(last+a[i] , a[i]);
        ans = max(ans , last);
    }
    return ans;
}

//with index of the segment
int maxSubArray(){
    ll last = -inf18 , ans = -inf18;
    int start = 0, end = -1, f = 0;
    for (int i = 0; i < n; i++){
        if (last + a[i] < a[i])
            f = i;
        last = max(last + a[i], a[i]);
        if (last > ans)
        {
            ans = last;
            start = f;
            end = i;
        }
    }  
    return ans;
}