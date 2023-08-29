#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Manacher's Algorithm for string:
struct Manacher{
    int n;
    string s;
    // d1 : odd
    // d2 : even
    vector<int> d1, d2;
    
    Manacher(string s) : s(s)
    {
        n = s.size();
        d1.resize(n);
        d2.resize(n);
        // d1
        for (int i = 0, l = 0, r = -1; i < n; i++)
        {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
            {
                k++;
            }
            d1[i] = k--;
            if (i + k > r)
            {
                l = i - k;
                r = i + k;
            }
        }
        // d2
        for (int i = 0, l = 0, r = -1; i < n; i++)
        {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k])
            {
                k++;
            }
            d2[i] = k--;
            if (i + k > r)
            {
                l = i - k - 1;
                r = i + k;
            }
        }
    }

    //check if subString is palindrome O(1)
    bool isPal(int l, int r)
    {
        int len = r - l + 1;
        int i = l + r >> 1;
        if (len % 2)
            return d1[i] > len / 2;
        else
            return d2[i + 1] >= len / 2;
    }

    //get the number of palindrome subString in string O(n)
    ll numberOfPal(){
        ll odd = accumulate(d1.begin() , d1.end() , 0LL);
        ll even = accumulate(d2.begin() , d2.end() , 0LL);
        ll count = even + odd;
        return count;
    }

    //get longest palindrome subString
    string getLongestPalindrome(){ 
        int oddIndex = 0 , evenIndex = 0;
        for (int i = 0; i < n; i++){
            if(d1[i] > d1[oddIndex]) oddIndex = i;
            if(d2[i] > d2[evenIndex]) evenIndex = i;
        }
        string even = s.substr(evenIndex-d2[evenIndex] , d2[evenIndex]*2);
        string odd = s.substr(oddIndex-d1[oddIndex]+1 , d1[oddIndex]*2-1);
        return even.size() >= odd.size() ? even : odd;
    }
};


//Manacher's Algorithm for numbers:
struct Manacher{
    int n;
    // d1 : odd
    // d2 : even
    vector<int> d1, d2 , v;
    
    Manacher(vector<int> v) : v(v)
    {
        n = v.size();
        d1.resize(n);
        d2.resize(n);
        // d1
        for (int i = 0, l = 0, r = -1; i < n; i++)
        {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && v[i - k] == v[i + k])
            {
                k++;
            }
            d1[i] = k--;
            if (i + k > r)
            {
                l = i - k;
                r = i + k;
            }
        }
        // d2
        for (int i = 0, l = 0, r = -1; i < n; i++)
        {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && v[i - k - 1] == v[i + k])
            {
                k++;
            }
            d2[i] = k--;
            if (i + k > r)
            {
                l = i - k - 1;
                r = i + k;
            }
        }
    }

    //check if subArray is palindrome O(1)
    bool isPal(int l, int r)
    {
        int len = r - l + 1;
        int i = l + r >> 1;
        if (len % 2)
            return d1[i] > len / 2;
        else
            return d2[i + 1] >= len / 2;
    }

    //get the number of palindrome subArray in array O(n)
    ll numberOfPal(){
        ll odd = accumulate(d1.begin() , d1.end() , 0LL);
        ll even = accumulate(d2.begin() , d2.end() , 0LL);
        ll count = even + odd;
        return count;
    }

    // get longest palindrome subArray
    pair<int , int> getLongestPalindrome(){ 
        int oddIndex = 0 , evenIndex = 0;
        for (int i = 0; i < n; i++){
            if(d1[i] > d1[oddIndex]) oddIndex = i;
            if(d2[i] > d2[evenIndex]) evenIndex = i;
        }
        int l1 = evenIndex-d2[evenIndex] , r1 = l1+(d2[evenIndex]*2)-1;
        int l2 = oddIndex-d1[oddIndex]+1 , r2 = l2+(d1[oddIndex]*2-1)-1;
        return r1-l1+1 >= r2-l2+1 ? make_pair(l1 , r1) : make_pair(l2 , r2);
    }
};