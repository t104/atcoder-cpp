#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int n;
int ans = 100100100;

void dfs(int i, int x, int y, vector<int>& t) {
    if(i == n) {
        int time = max(x, y);
        ans = min(ans, time);
        return;
    }

    dfs(i + 1, x + t.at(i), y, t);
    dfs(i + 1, x, y + t.at(i), t);
}

int main() {
    cin >> n;
    vector<int> t(n);
    rep(i, n) cin >> t.at(i);

    dfs(0, 0, 0, t);

    cout << ans << endl;

    return 0;
}