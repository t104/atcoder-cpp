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
    int m;
    cin >> m;
    vector<string> sa(m), sb(m);
    rep(i,m) {
        string s;
        cin >> s;
        sa[i] = s.substr(0, 3);
        sb[i] = s.substr(s.size()-3);
    }
    map<string, int> mp;
    rep(i,m) mp[sa[i]] = 0, mp[sb[i]] = 0;
    int n = 0;
    for (auto& p : mp) p.second = n++;

    vector<vector<int>> to(n);
    vector<int> deg(n);
    rep(i,m) {
        int a = mp[sa[i]];
        int b = mp[sb[i]];
        to[b].push_back(a);
        deg[a]++;
    }

    queue<int> q;
    vector<int> ans(n);
    rep(i,n) {
        if (deg[i] == 0) {
            ans[i] = -1;
            q.push(i);
        }
    }
    while (q.size()) {
        int v = q.front(); q.pop();
        if (ans[v] == -1) {
            for (int u : to[v]) {
                if (ans[u]) continue;
                ans[u] = 1;
                q.push(u);
            }
        } else {
            for (int u : to[v]) {
                if (ans[u]) continue;
                deg[u]--;
                if (deg[u] == 0) {
                    ans[u] = -1;
                    q.push(u);
                }
            }
        }
    }

    rep(i,m) {
        int b = mp[sb[i]];
        if (ans[b] == -1) cout << "Takahashi" << endl;
        else if (ans[b] == 0) cout << "Draw" << endl;
        else cout << "Aoki" << endl;
    }
    return 0;
}