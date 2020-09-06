#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int n, m;
int ans = 1;

void dfs(int i, vector<bool> v, vector<set<int>>& relation) {
    if(i == n) {
        vector<int> members;
        rep(j, n) {
            if(v.at(j)) members.push_back(j);
        }

        for(int j : members) {
            for(int k : members) {
                if(j != k && !relation.at(j).count(k)) return;
            }
        }

        ans = max(ans, (int) members.size());
        return;
    }

    v.at(i) = true;
    dfs(i + 1, v, relation);

    v.at(i) = false;
    dfs(i + 1, v, relation);
}

int main() {
    cin >> n >> m;
    vector<set<int>> relation(n);
    rep(i, m) {
        int j, k;
        cin >> j >> k;
        j--; k--;
        relation.at(j).insert(k);
        relation.at(k).insert(j);
    }

    vector<bool> v(n);

    dfs(0, v, relation);

    cout << ans << endl;

    return 0;
}
