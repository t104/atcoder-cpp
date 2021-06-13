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

using mint = modint1000000007;

struct Matrix {
    int sz;
    vector<vector<mint>> val;

    Matrix(int sz): sz(sz) {
        val.resize(sz, vector<mint>(sz));
    }

    Matrix multiply(Matrix &another) {
        Matrix res(sz);
        rep(i,sz) {
            rep(j,sz) {
                rep(k,sz) {
                    res.val[i][j] += val[i][k] * another.val[k][j];
                }
            }
        }
        return res;
    }

    Matrix power(ll x) {
        vector<Matrix> memo(63, Matrix(sz));
        memo[0].val = val;
        rep(i,62) {
            memo[i+1] = memo[i].multiply(memo[i]);
        }

        Matrix res(sz);
        rep(i,sz) {
            res.val[i][i] = 1;
        }
        for (int i = 62; 0 <= i; --i) {
            while ((1LL << i) <= x) {
                x -= 1LL << i;
                res = res.multiply(memo[i]);
            }
        }
        return res;
    }

    void print() {
        rep(i,sz) {
            rep(j,sz) {
                cout << val[i][j].val() << ' ';
            }
            cout << endl;
        }
    }

};

int main() {
    int k, b;
    ll n;
    cin >> n >> b >> k;
    vector<int> c(k);
    rep(i,k) cin >> c[i];

    // 行列 A を求める
    Matrix A(b);
    rep(i,b) {
        for (auto ci: c) {
            int r = (i * 10 + ci) % b;
            A.val[i][r]++;
        }
    }

    Matrix ans = A.power(n);
    cout << ans.val[0][0].val() << endl;

    return 0;
}