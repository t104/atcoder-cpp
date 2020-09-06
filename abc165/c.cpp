#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int a[55], b[55], c[55], d[55];

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    rep(i, q) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    ll ans = 0;
    vector<int> comb(m + n);
    rep(i, m) comb.at(i) = 1;
    reverse(comb.begin(), comb.end());
    do {
        vector<int> A;
        int k = 0;
        rep(i, n + m) {
            if(comb.at(i) == 0) A.push_back(k);
            else {
                k++;
            }
        }
        ll sum = 0;
        rep(i, q) {
            if(A.at(b[i] - 1) - A.at(a[i] - 1) == c[i]) {
                sum += d[i];
            }
        }
        ans = max(ans, sum);
    } while(next_permutation(comb.begin(), comb.end()));

    cout << ans << endl;
    return 0;
}