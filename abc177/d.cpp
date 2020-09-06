#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<vector<int>> relations;
vector<int> visited;
int ans = 0, now = 0;

void dfs (int x) {
    visited.at(x) = 1;
    now++;
    for (auto i : relations.at(x)) {
        if (!visited.at(i)) dfs(i);
    }
}


int main() {
    int n,m;
    cin >> n >> m;
    relations.resize(n);
    visited.resize(n);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        relations.at(a).push_back(b);
        relations.at(b).push_back(a);
    }

    rep(i,n) {
        now = 0;
        dfs(i);
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}
