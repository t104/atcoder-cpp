#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int k, t;
    cin >> k >> t;
    vector<int> a(t);
    rep(i,t) cin >> a.at(i);

    sort(a.rbegin(), a.rend());
    int ans = k - 1 - 2 * (k - a.at(0));
    if (ans < 0) ans = 0;
    cout << ans << endl;
    return 0;
}