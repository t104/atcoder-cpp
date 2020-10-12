#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }
const int max_n = 55;

vector<bool> visited(max_n);
vector<vector<bool>> graph(max_n,vector<bool>(max_n, false));

void dfs(int p) {
    if (visited.at(p)) return;
    visited.at(p) = true;
    rep(i,max_n) {
        if (graph.at(p).at(i)) dfs(i);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph.at(a).at(b) = true;
        graph.at(b).at(a) = true;
    }

    int ans = 0;
    rep(i,n) {
        for (int j = i + 1; j < n; ++j) {
            if (!graph.at(i).at(j)) continue;
            graph.at(i).at(j) = false;
            graph.at(j).at(i) = false;
            rep(k,n) visited.at(k) = false;
            dfs(0);
            bool ok = false;
            rep(k,n) {
                if (!visited.at(k)) {
                    ok = true;
                    break;
                }
            }
            if (ok) ans++;
            graph.at(i).at(j) = true;
            graph.at(j).at(i) = true;
        }
    }
    cout << ans << endl;
    return 0;
}