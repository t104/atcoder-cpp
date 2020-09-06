#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int n;
ll ans = -1;

void dfs(int i, ll leaf, vector<ll> &node, vector<int> &a) {
    if(i == n-1) {
        if(node.at(i) != a.at(i)) return;
        ll tot = 0;
        rep(i, n) {
            tot += node.at(i);
        }
        ans = max(ans, tot);
        return;
    }

    ll root = node.at(i) - a.at(i);
    leaf -= a.at(i);
    if(root <= 0) return;
    node.at(i+1) = min(root * 2, leaf);
    dfs(i+1, leaf, node, a);
}

int main() {
    cin >> n;
    n++;
    vector<int> a(n);
    ll leaf = 0;
    rep(i, n) {
        cin >> a.at(i);
        leaf += a.at(i);
    }

    vector<ll> node(n);
    node.at(0) = 1;
    dfs(0, leaf, node, a);
    cout << ans << endl;
    return 0;
}