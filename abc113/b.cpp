#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n, t, a;
    cin >> n >> t >> a;
    vector<int> h(n);
    int ans = -1, mh = 1001001001;
    rep(i, n) cin >> h.at(i);

    rep(i, n) {
        int d = abs(1000 * a - (1000 * t - 6 * h.at(i)));
        if(mh > d) {
            ans = i;
            mh = d;
        }
    }

    cout << ans + 1 << endl;

    return 0;
}