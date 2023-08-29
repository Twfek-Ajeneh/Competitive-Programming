#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (int)1e9

//Rabin Karp Matching:
//to find all occurrences of s in t

vector<int> rabin_karp_matching(string const& s, string const& t){
    const int p1=1333, p2=137; // 31 , 53 , 137 , 1331 , 1333
	const int m1=1e9+9, m2=1e9+7; // 1e9+7 , 1e9+9
    int S = s.size(), T = t.size();

	vector<ll> pow1(max(S , T)), pow2 (max(S , T));
    vector<ll> h1(T+1 , 0), h2(T+1 , 0);
    pair<ll , ll> h_s = {0 , 0};

    pow1[0] = 1 , pow2[0] = 1;
    for (int i = 1; i < (int)pow1.size(); i++) {
        pow1[i] = (pow1[i-1] * p1) % m1;
        pow2[i] = (pow2[i-1] * p2) % m2;
    }

    h1[0]=t[0]-'a'+1;
    h2[0]=t[0]-'a'+1;
    for(int i=1 ; i<T ; i++){
        h1[i] = (h1[i-1]*p1 + t[i]-'a'+1)%m1;
        h2[i] = (h2[i-1]*p2 + t[i]-'a'+1)%m2;
    }

    for (int i = 0; i < S; i++) {
        h_s.first = (h_s.first*p1 + s[i]-'a'+1)%m1;
        h_s.second = (h_s.second*p2 + s[i]-'a'+1)%m2;
    }

    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) { 
        int j = i+S-1;
        pair<ll , ll> h_t = {0 , 0};
        
        //calc first hash
        h_t.first = h1[j];
        if(i) h_t.first -= h1[i-1] * pow1[j-i+1];
        h_t.first = (h_t.first%m1 + m1)%m1;

        //calc second hash
        h_t.second = h2[j];
        if(i) h_t.second -= h2[i-1] * pow2[j-i+1];
        h_t.second = (h_t.second%m2 + m2)%m2;

        if(h_t==h_s) occurrences.push_back(i);
    }

    return occurrences;
}
