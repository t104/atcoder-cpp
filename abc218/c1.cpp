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

using Mat = vector<vector<int>>;

Mat rotate90(Mat &a) {
    int n = a.size(), m = a[0].size();
    // a は正方行列
    assert(n == m);
    Mat res(n, vector<int>(n));
    rep(i,n) rep(j,n) {
        res[j][n-1-i] = a[i][j];
    }
    return res;
}

void print(Mat &a) {
    int n = a.size(), m = a[0].size();
    rep(i,n) {
        rep(j,m) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "======================================" << endl;
}

P top_left(Mat &a) {
    int top = a.size(), left = a[0].size();
    rep(i, a.size()) rep(j, a[0].size()) {
        if (a[i][j]) {
            chmin(top, i);
            chmin(left, j);
        }
    }
    return make_pair(top, left);
}

bool equals(Mat &a, Mat &b) {
    auto [top_a, left_a] = top_left(a);
    auto [top_b, left_b] = top_left(b);
    int n = a.size(), m = a[0].size();
    for (int ai = top_a, bi = top_b; ai < n && bi < n; ++ai, ++bi) {
        for (int aj = left_a, bj = left_b; aj < m && bj < m; ++aj, ++bj) {
            if (a[ai][aj] != b[bi][bj]) return false;
        }
    }
    return true;
}

int main() {
    int n, N;
    cin >> n;
    N =  2*n;
    vector<vector<int>> a(N, vector<int>(N)), b(N, vector<int>(N));
    rep(i,n) rep(j,n) {
        char c;
        cin >> c;
        a[i][j] = c == '#';
    }
    rep(i,n) rep(j,n) {
        char c;
        cin >> c;
        b[i][j] = c == '#';
    }
    rep(i,4) {
        if (equals(a, b)) {
            cout << "Yes" << endl;
            return 0;
        }
        a = rotate90(a);
        // print(a);
    }
    cout << "No" << endl;
    return 0;
}