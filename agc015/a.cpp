#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    ll summin = b + (ll)(n-1) * a;
    ll summax = a + (ll)(n-1) * b;
    ll ans = summax - summin + 1;
    if (0 <= ans) cout << ans << endl;
    else cout << 0 << endl;
    return 0;
}