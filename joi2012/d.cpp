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
using P = pair<int,int>;

const int MX = 5005;
vector<vector<int>> cnt(MX, vector<int>(MX));

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m), x(m);
    rep(i,m) {
        cin >> a[i] >> b[i] >> x[i];
        a[i]--, b[i]--;
    }

    rep(i,m) {
        cnt[a[i]][b[i]]++;
        cnt[a[i]][b[i] + 1]--;
        cnt[a[i] + x[i] + 1][b[i]]--;
        cnt[a[i] + x[i] + 1][b[i] + x[i] + 2]++;
        cnt[a[i] + x[i] + 2][b[i] + 1]++;
        cnt[a[i] + x[i] + 2][b[i] + x[i] + 2]--;
    }
    
    rep(i,n) {
        rep(j,n) {
            cnt[j+1][i] += cnt[j][i];
        }
    }

    rep(i,n) {
        rep(j,n) {
            cnt[i][j+1] += cnt[i][j];
        }
    }

    rep(i,n) {
        rep(j,n) {
            if (n < i+j) break;
            cnt[i+j+1][j+1] += cnt[i+j][j];
        }
    }

    int ans = 0;
    rep(i,n) {
        for (int j = 0; j <= i; ++j) {
            if (cnt[i][j]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}