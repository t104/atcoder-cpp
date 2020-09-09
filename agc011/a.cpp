#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> t(n);
    rep(i,n) cin >> t.at(i);

    sort(t.begin(), t.end());
    int ans = 0, top = 0;
    queue<int> q;
    rep(i,n) {
        if (!q.empty()) {
            while (!q.empty() && q.front() + k < t.at(i)) {
                ans++;
                for (int i = 0; !q.empty() && i < c; ++i) {
                    q.pop();
                }
            }
        }
        q.push(t.at(i));
    }

    while (!q.empty()) {
        ans++;
        for (int i = 0; !q.empty() && i < c; ++i) {
            q.pop();
        }
    }

    cout << ans << endl;
    return 0;
}