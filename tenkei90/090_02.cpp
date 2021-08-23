#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define INF 1001001001
#define LINF (1LL<<60)
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){ return a > b && (a = b, true); }
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){ return a < b && (a = b, true); }
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using ld = long double;
using P = pair<int,int>;

using mint = modint998244353;

struct Matrix {
    vector<vector<mint>> val;
    
    Matrix(int n, int m) {
        val = vector<vector<mint>>(n, vector<mint>(m));
    }

    Matrix(vector<vector<mint>> mat): val(mat) {}

    Matrix multiply (Matrix mat) {
        int n = val.size();
        int m = mat.val[0].size();
        Matrix res(n, m);
        rep(i,n) rep(j,m) rep(k,n) {
            res.val[i][j] += val[i][k] * mat.val[k][j];
        }
        return res;
    }

    Matrix pow(ll n) {
        if (n == 0) {
            return Matrix({{1,0}, {0,1}});
        }
        if (n%2 == 0) {
            Matrix half = pow(n/2);
            return half.multiply(half);
        }
        Matrix res(val);
        return res.multiply(pow(n-1));
    }

    void print() {
        for (auto v: val) {
            for (auto i : v) {
                cout << i.val() << ' ';
            }
            cout << endl;
        }
    }
};

int main() {
    ll n, k;
    cin >> n >> k;
    assert(k == 1);
    Matrix a({{1,1}, {1,0}});
    Matrix b(vector<vector<mint>> {{1}, {1}});
    auto c = a.pow(n-1).multiply(b);
    auto ans = c.val[0][0] + c.val[1][0];
    cout << ans.val() << endl;
    return 0;
}