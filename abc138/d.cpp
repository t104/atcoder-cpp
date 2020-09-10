#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<vector<int>> g;
vector<int> ans;
vector<bool> visited;

void dfs(int now) {
    visited.at(now) = true;
    for (int next : g.at(now)) {
        if (!visited.at(next)) {
            ans.at(next) += ans.at(now);
            dfs(next);
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    g.resize(n);
    rep(i,n-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g.at(a).push_back(b);
        g.at(b).push_back(a);
    }

    ans.resize(n);
    visited.resize(n, false);
    rep(i,q) {
        int p, x;
        cin >> p >> x;
        p--;
        ans.at(p) += x;
    }
    dfs(0);
    rep(i,n) cout << ans.at(i) << endl;
    return 0;
}