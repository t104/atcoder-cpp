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


int main() {
    int n;
    cin >> n;
    vector<vector<ll>> c(n, vector<ll>(n));
    rep(i,n) rep(j,n) cin >> c[i][j];
    vector<ll> db(n, -LINF);
    rep(i,n) rep(j,n-1) {
        if (db[j] == -LINF)
            db[j] = c[i][j+1] - c[i][j];
        else if (db[j] != c[i][j+1] - c[i][j]) {
            cout << "No" << endl;
            return 0;
        }
    }

    vector<ll> b(n), a(n);
    ll bmi = 0;
    rep(i,n-1) {
        b[i+1] += b[i] + db[i];
        chmin(bmi, b[i+1]);
    }
    rep(i,n) b[i] -= bmi;

    rep(i,n) {
        a[i] = c[i][0] - b[0];
        if (a[i] < 0) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    rep(i,n) {
        cout << a[i];
        if (i != n-1) cout << ' ';
    }
    cout << endl;
    rep(i,n) {
        cout << b[i];
        if (i != n-1) cout << ' ';
    }
    cout << endl;
    return 0;
}