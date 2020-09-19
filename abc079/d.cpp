#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<vector<int>> c(10, vector<int>(10));
vector<int> cost(10);

void dfs(int start, int now, int total, vector<bool> visited) {
    visited.at(now) = true;
    if (now == 1) {
        cost.at(start) = min(cost.at(start), total);
    }
    rep(i, 10) {
        if (visited.at(i)) continue;
        int t = total + c.at(now).at(i);
        if (t < cost.at(start)) dfs(start, i, t, visited);
    }
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> wall(h, vector<int>(w));
    rep(i, 10) rep(j, 10) cin >> c.at(i).at(j);
    rep(i, h) rep(j, w) cin >> wall.at(i).at(j);
    
    rep(i, 10) cost.at(i) = c.at(i).at(1);
    rep(i, 10) dfs(i, i, 0, vector<bool>(10, false));

    ll ans = 0;
    rep(i, h) rep(j, w) {
        if (wall.at(i).at(j) == -1) continue;
        ans += cost.at(wall.at(i).at(j));
    }

    cout << ans << endl;
    return 0;
}