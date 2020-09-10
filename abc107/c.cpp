#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    rep(i,n) cin >> x.at(i);

    int ans = 1e9;
    rep(i, n-k+1) {
        ans = min(ans, abs(x.at(i)) + abs(x.at(i) - x.at(i+k-1)));
        ans = min(ans, abs(x.at(i+k-1)) + abs(x.at(i) - x.at(i+k-1)));
    }
    cout << ans << endl;
    return 0;
}
