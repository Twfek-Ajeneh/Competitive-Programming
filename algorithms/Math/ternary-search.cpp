#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Ternary Search for Double:
double ternary_search(double l, double r) {
    double eps = 1e-9; //error limit
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);
        double f2 = f(m2);
        if (f1 < f2) //for min-range just reverse the condition
            l = m1;
        else
            r = m2;
    }
    return f(l);
}

//Ternary Search for Integer:
vector<int> a;

int ternary_search(int l, int r) {
    while (r - l >= 3) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        int f1 = a[m1];
        int f2 = a[m2];
        if (f1 < f2) //for min-range just reverse the condition to >
            l = m1;
        else
            r = m2;
    }
    return max(a[l] , a[l+1]); //change for min
}