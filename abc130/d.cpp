#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);

    ll ans = 0, sum = 0;
    int r = 0;
    rep(l,n) {
        while(sum < k) {
            if(r == n) break;
            sum += a.at(r);
            r++;
        }
        if(sum < k) break;
        ans += n-r+1;
        sum -= a.at(l);
    }

    cout << ans << endl;
    return 0;
}
