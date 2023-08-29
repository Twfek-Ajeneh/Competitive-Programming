#include <bits/stdc++.h>
#define ll long long
#define MOD (int)(1e9+7)
using namespace std;

//Matrix struct:
template<class T>

struct Matrix {
    int n;
    vector<vector<T>> g;

    Matrix(int n, function<T (int, int)> init = [](...){return 0;})
        : n(n), g(n, vector<T>(n)) {
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<n ; j++)
            g[i][j] = init(i, j);
    };

    auto& operator [] (int i) {
        return g[i];
    }

    auto operator * (Matrix h) {
        Matrix f(n);
        for(int i=n; i--;)
            for(int k=n; k--;)
            for(int j=n; j--;)
               f[i][j] = (f[i][j] + g[i][k] * h[k][j]) % MOD;
        return f;
    }

    auto operator * (vector<T> h) {
        vector<T> f(n, 0);
        for(int i=n; i--;)
            for(int j=n; j--;)
                f[i] = (f[i] + g[i][j] * h[j]) % MOD;
        return f;
    }

    auto operator + (Matrix<T> h) {
        Matrix<T> f(n);
        for(int i=n; i--;)
            for(int j=n; j--;)
                f[i][j] =  (g[i][j] + h[i][j]) % MOD;
        return f;
    }

    auto operator ^ (ll p) {
        Matrix f(n, [](int i, int j) { return i==j; });
        Matrix g = *this;
        for( ; p ; p>>=1, g = g*g) 
            if(p&1) f = f * g;
        return f;
    }
};

// every row in the matrix product with the elements from vector
/* how to use:
Matrix<int> mat(10, [&](int i, int j) {
        int x; cin>>x; return x;
    }); */


//Matrix functions:
typedef vector <int> Row;
typedef vector <Row> Matrix;
const int Mod = 1e9 + 7;

void add_self(int& x, int y)
{
    if((x += y) >= Mod) x -= Mod;
}

int mul(int x, int y)
{
    return (ll) x * y % Mod;
}

Matrix Zero(int n, int m)
{
    return Matrix(n, Row(m, 0));
}

Matrix Ident(int n)
{
    Matrix Res = Zero(n, n);
    for(int i = 0; i < n; i++)  Res[i][i] = 1;
    return Res;
}

Matrix Multy(const Matrix& A, const Matrix& B)
{
    assert(A[0].size() == B.size());
    Matrix Res = Zero(A.size(), B[0].size());

    for(int i = 0; i < Res.size(); i++)
        for(int j = 0; j < Res[0].size(); j++)
            for(int k = 0; k < B.size(); k++)
                add_self(Res[i][j], mul(A[i][k], B[k][j]));

    return Res;
}

Matrix Power(const Matrix& A, ll k)
{
    if(!k)      return Ident(A.size());
    if(k & 1)   return Multy(A, Power(A, k - 1));
    return Power(Multy(A, A), k / 2);
}