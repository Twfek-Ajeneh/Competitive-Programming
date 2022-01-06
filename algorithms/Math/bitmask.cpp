#include <bits/stdc++.h>
using namespace std;
#define ll long long

// to choose and check bitmask:
// for(int mask=0 ; mask<1<<n ; mask++) {
//     for(int i=0 ; i<n ; i++) {
//         if(mask&1<<i) {
//          // ...
//         }
//     }
// }


// convert binary to int:

ll toInt(string binary){
    unsigned long decimal = std::bitset<21>(binary).to_ulong(); //change the number of bits
    return decimal;
}


// convert int to binary:

string toBinary(int n){
    std::string binary = std::bitset<21>(n).to_string(); //change number of bits
    for (int i = 0; i < binary.size(); i++)
        if(binary[i]=='1'){
            binary.erase(binary.begin() , binary.begin()+i);
            break;
        }
    return binary;
}


//binary to decimal:

ll binaryToDecimal(vector <int> a){
    ll j=0;
    ll sum=0;
    for(int i=a.size()-1;i>=0;i--){
        if(a[i] == 1)
            sum+=pow(2,j);
        j++;
    }
    return sum;
}


// xnor :

int xnor(int x, int y){
    if (x < y)
        swap(x, y);
    if (x == 0 && y == 0)
        return 1;
    int a_rem = 0; // for last bit of x
    int b_rem = 0; // for last bit of y
    int count = 0;
    int xnornum = 0;
    while (x)
    {
        a_rem = x & 1;
        b_rem = y & 1;
        if (a_rem == b_rem)
            xnornum |= (1 << count);
        count++;
        x = x >> 1;
        y = y >> 1;
    }
    return xnornum;
}