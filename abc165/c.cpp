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

int n, m, q;

vector<vector<int>> As;

void dfs(vector<int> A = {1}) {
    if (A.size() == n+1) {
        As.push_back(A);
        return;
    }
    for (int i = A.back(); i <= m; ++i) {
        vector<int> next = A;
        next.push_back(i);
        dfs(next);
    }
}

int main() {
    cin >> n >> m >> q;
    vector<int> a(q), b(q), c(q), d(q);
    rep(i,q) cin >> a[i] >> b[i] >> c[i] >> d[i];
    dfs();

    int ans = 0;

    for (auto A: As) {
        int cnt = 0;
        rep(i,q) {
            if (A[b[i]] - A[a[i]] == c[i]) cnt += d[i];
        }
        chmax(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}