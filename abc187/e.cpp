#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define INF 1001001001
#define LINF (1LL<<60)
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using P = pair<int,int>;

int n;
vector<int> a,b;
vector<vector<int>> g;
vector<int> depth;
vector<ll> dp;

void depth_dfs(int now, int d) {
    if (0 <= depth[now]) return;
    depth[now] = d;
    for (auto next: g[now]) {
        depth_dfs(next, d+1);
    }
}

void imos_dfs(int now, ll sum) {
    sum += dp[now];
    dp[now] = sum;
    for (auto next: g[now]) {
        if (depth[now] < depth[next]) {
            imos_dfs(next, sum);
        }
    }
}

int main() {
    cin >> n;
    a.resize(n-1);
    b.resize(n-1);
    g.resize(n);
    depth.resize(n, -1);
    dp.resize(n);

    rep(i,n-1) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        g.at(a[i]).push_back(b[i]);
        g.at(b[i]).push_back(a[i]);
    }

    depth_dfs(0,0);

    int q;
    cin >> q;
    
    rep(i,q) {
        int t, e, x;
        cin >> t >> e >> x;
        --e;

        int va, vb;
        va = a[e];
        vb = b[e];
        if (t == 2) swap(va, vb);

        if (depth[va] < depth[vb]) {
            dp[0] += x;
            dp[vb] -= x;
        }
        else {
            dp[va] += x;
        }
    }

    // rep(i,n) {
    //     cout << dp[i] << endl;
    // }

    imos_dfs(0, 0);

    rep(i,n) {
        cout << dp[i] << endl;
    }

    return 0;
}