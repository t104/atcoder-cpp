#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);

    int ans = 0;
    rep(i,n) {
        ans += a.at(i);
    }
    ans -= n;

    cout << ans << endl;
    return 0;
}