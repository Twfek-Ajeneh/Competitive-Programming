#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (int)1e9

//Single Hash for string:
struct Hash{
	const int p = 1333; // 31 , 53 , 137 , 1331 , 1333
	const int m = 1e9+9; // 1e9+7 , 1e9+9
	vector<ll> pow, h;
	
	void build(string s) {
		int n = s.size();
		pow.resize(n);
		h.resize(n);
		pow[0]=1;
		for(int i=1 ; i<n ; i++) pow[i] = pow[i-1]*p%m;
		h[0]=s[0]-'0'+1;
		for(int i=1 ; i<n ; i++) h[i] = (h[i-1]*p + s[i]-'0'+1)%m;
	}
	
    void add(string s){
        for (int i = 0; i < s.size(); i++) pow.push_back(pow.back()*p%m);
        for (int i = 0; i < s.size(); i++) h.push_back((h.back()*p + s[i]-'0'+1)%m);
    }

	ll getHash(int i, int j) {
		ll ret = h[j];
		if(i) ret -= h[i-1] * pow[j-i+1];
		return (ret%m + m)%m;
	}
};


//Double Hash for string:
struct DoubleHash{
	const int p1=1333, p2=137; // 31 , 53 , 137 , 1331 , 1333
	const int m1=1e9+9, m2=1e9+7; // 1e9+7 , 1e9+9
	vector<ll> pow1, pow2, h1, h2;

	void build(string s) {
		int n = s.size();

		pow1.resize(n);
		h1.resize(n);
		pow1[0]=1;
		for(int i=1 ; i<n ; i++) pow1[i] = pow1[i-1]*p1%m1;
		h1[0]=s[0]-'a'+1;
		for(int i=1 ; i<n ; i++) h1[i] = (h1[i-1]*p1 + s[i]-'a'+1)%m1;

		pow2.resize(n);
		h2.resize(n);
		pow2[0]=1;
		for(int i=1 ; i<n ; i++) pow2[i] = pow2[i-1]*p2%m2;
		h2[0]=s[0]-'a'+1;
		for(int i=1 ; i<n ; i++) h2[i] = (h2[i-1]*p2 + s[i]-'a'+1)%m2;
	}

	void add(string s){
        for (int i = 0; i < s.size(); i++) pow1.push_back(pow1.back()*p1%m1);
        for (int i = 0; i < s.size(); i++) h1.push_back((h1.back()*p1 + s[i]-'0'+1)%m1);
		
		for (int i = 0; i < s.size(); i++) pow2.push_back(pow2.back()*p2%m2);
        for (int i = 0; i < s.size(); i++) h2.push_back((h2.back()*p2 + s[i]-'0'+1)%m2);
    }

	pair<int, int> getHash(int i, int j){
		ll a = h1[j];
		if(i) a -= h1[i-1] * pow1[j-i+1];
		a = (a%m1 + m1)%m1;

		ll b = h2[j];
		if(i) b -= h2[i-1] * pow2[j-i+1];
		b = (b%m2 + m2)%m2;

		return make_pair(a,b);
	}
};


//Double Hash for number:
struct DoubleHash{
	const int p1=53, p2=137; // 31 , 53 , 137 , 1331 , 1333
	const int m1=1e9+9, m2=1e9+7; // 1e9+7 , 1e9+9
	vector<ll> pow1, pow2, h1, h2;
    int end = 0;

	void build(int num) {
		int n = 1;
        end++;

		pow1.resize(n);
		h1.resize(n); 
		pow1[0]=1;
		h1[0]=num+1;

		pow2.resize(n);
		h2.resize(n);
		pow2[0]=1;
		h2[0]=num+1;
	}

	void add(int num){
        end++;
        pow1.push_back(pow1.back()*p1%m1);
        h1.push_back((h1.back()*p1 + num+1)%m1);

        pow2.push_back(pow2.back()*p2%m2);
        h2.push_back((h2.back()*p2 + num+1)%m2);
    }

	pair<int, int> getHash(int i, int j){
		ll a = h1[j];
		if(i) a -= h1[i-1] * pow1[j-i+1];
		a = (a%m1 + m1)%m1;

		ll b = h2[j];
		if(i) b -= h2[i-1] * pow2[j-i+1];
		b = (b%m2 + m2)%m2;

		return make_pair(a,b);
	}
};