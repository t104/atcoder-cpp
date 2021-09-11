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

int n, N;

P top_left(vector<vector<int>> &x) {
    int top = N, left = N;
    rep(i,N) rep(j,N) {
        if (x[i][j] == 1) {
            chmin(top, i);
            chmin(left, j);
        }
    }
    return make_pair(top, left);
}

bool equals(vector<vector<int>> &x, vector<vector<int>> &y) {
    auto [xtop, xleft] = top_left(x);
    auto [ytop, yleft] = top_left(y);
    for (int xi = xtop, yi = ytop; xi < N && yi < N; ++xi, ++yi) {
        for (int xj = xleft, yj = yleft; xj < N && yj < N; ++xj, ++yj) {
            if (x[xi][xj] != y[yi][yj]) {
                return false;
            }
        }
    }
    return true;
}

vector<vector<int>> rot(vector<vector<int>> x) {
    vector<vector<int>> res(N, vector<int>(N));
    rep(i,N) rep(j,N) {
        res[j][N-1-i] = x[i][j];
    }
    return res;
}

void print(vector<vector<int>> &x) {
    rep(i,N) {
        rep(j,N) cout << x[i][j] << ' ';
        cout << endl;
    }
    cout << "======================" << endl;
}

int main() {
    cin >> n;
    N = 2*n;
    vector<string> s(n), t(n);
    rep(i,n) cin >> s[i];
    rep(i,n) cin >> t[i];
    vector<vector<int>> a(N, vector<int>(N)), b(N, vector<int>(N));
    rep(i,n) rep(j,n) a[i][j] = s[i][j] == '#';
    rep(i,n) rep(j,n) b[i][j] = t[i][j] == '#';

    rep(i,4) {
        // print(a);
        if (equals(a,b)) {
            cout << "Yes" << endl;
            return 0;
        }
        a = rot(a);
    }
    cout << "No" << endl;
    return 0;
}

