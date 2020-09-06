#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const int MAX_N = 12;
const int INF = 100100100;

vector<int> c(MAX_N);
vector<vector<int>> a(MAX_N, vector<int>(MAX_N));
int n, m, x;
int ans = INF;

void dfs(int i, int cost, vector<int> p) {
    if (i == n) {
        bool ok = true;
        rep(j, m) {
            ok = ok && x <= p.at(j);
        }
        if(ok) ans = min(ans, cost);
        return;
    }
    dfs(i + 1, cost, p);
    rep(j, m) {
        p.at(j) += a.at(i).at(j);
    }
    dfs(i + 1, cost + c.at(i), p);
}

int main() {
    cin >> n >> m >> x;
    rep(i, n) {
        cin >> c.at(i);
        rep(j, m) {
            cin >> a.at(i).at(j);
        }
    }

    dfs(0, 0, vector<int>(m, 0));
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}