#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int a, b, m;
    cin >> a >> b >> m;
    vector<int> pa(a), pb(b);
    
    rep(i, a) cin >> pa.at(i);

    rep(i, b) cin >> pb.at(i);

    vector<vector<int>> discount(m, vector<int>(3));
    rep(i, m) {
        rep(j, 3) {
            cin >> discount.at(i).at(j);
        }
    }

    vector<int> price(m);
    rep(i, m) {
        price.at(i) = pa.at(discount.at(i).at(0) - 1)
        + pb.at(discount.at(i).at(1) - 1)
        - discount.at(i).at(2);
    }
    sort(price.begin(), price.end());
    sort(pa.begin(), pa.end());
    sort(pb.begin(), pb.end());

    int ans = 100100100;
    ans = min(ans, price.at(0));
    ans = min(ans, pa.at(0) + pb.at(0));
    cout << ans << endl;
    return 0;
}