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
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i,m) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }
    vector<vector<int>> to(n), from(n);
    rep(i,m) {
        to[a[i]].push_back(b[i]);
        from[b[i]].push_back(a[i]);
    }
    vector<int> ans;
    vector<int> added(n);
    vector<int> used(n);
    priority_queue<int, vector<int>, greater<int>> que;
    rep(i,n) {
        if (from[i].size() == 0) {
            que.push(i);
            added[i] = 1;
        }
    }
    int idx = 0;
    while (que.size()) {
        auto i = que.top(); que.pop();
        if (used[i] == 1) continue;
        ans.push_back(i);
        used[i] = 1;
        for (auto &nv: to[i]) {
            if (added[nv] == 1) continue;
            bool ok = true;
            for (auto &f: from[nv]) {
                if (used[f] == 0) ok = false;
            }
            if (ok) {
                que.push(nv);
                added[nv] = 1;
            }
        }
    }
    rep(i,n) {
        if (used[i] == 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (auto &ai: ans) cout << ai+1 << ' ';
    cout << endl;
    return 0;
}

