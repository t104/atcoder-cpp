#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b;
    int pos = 0, neg = 0;
    rep(i,n) {
        cin >> a.at(i);
        if(a.at(i) < 0) {
            b.push_back(a.at(i));
            a.at(i) = -a.at(i);
        }
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    rep(i,n) {
            ans += a.at(i);
    }
    if(b.size()%2 != 0) {
        ans -= 2 * a.at(0);
    }
    cout << ans << endl;
    return 0;
}