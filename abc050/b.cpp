#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n;
    vector<int> t(n);
    rep(i, n) cin >> t.at(i);
    cin >> m;
    
    int sum = 0;
    rep(i, n) sum += t.at(i);

    vector<int> ans(m);
    rep(i, m) {
        int p, x;
        cin >> p >> x;
        p--;
        ans.at(i) = sum - t.at(p) + x;
    }
    rep(i, m) cout << ans.at(i) << endl;

    return 0;
}