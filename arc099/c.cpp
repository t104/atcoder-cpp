#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    n -= k;
    int ans = 1;
    ans += n/(k-1);
    if ((n%(k-1)) > 0) ans++;
    cout << ans << endl;
    return 0;
}