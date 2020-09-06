#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    rep(i,n) cin >> l.at(i);
    sort(l.begin(), l.end());
    int ans = 0;
    rep(i,n-2) {
        for (int j = i+1; j < n-1; ++j) {
            if (l.at(i) == l.at(j)) continue;
            for (int k = j + 1; k < n; ++k) {
                if (l.at(j) == l.at(k)) continue;
                if (l.at(i) + l.at(j) > l.at(k)) {
                    ++ans;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}