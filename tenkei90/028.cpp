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

void print_table(vector<vector<int>> &table, int h, int w) {
    rep(i,h) {
        rep(j,w) {
            cout << table[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> table(1005, vector<int>(1005));
    rep(i,n) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        lx++, ly++;
        table[lx][ly]++;
        table[lx][ry+1]--;
        table[rx+1][ly]--;
        table[rx+1][ry+1]++;
    }

    vector<int> cnt(n+1);
    rep(i,1001) rep(j,1001) {
        table[i+1][j+1] += table[i][j+1] + table[i+1][j] - table[i][j];
        cnt[table[i+1][j+1]]++;
    }

    for (int i = 1; i <= n; ++i) {
        cout << cnt[i] << endl;
    }

    // print_table(table, 10, 10);
    return 0;
}