#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<P> a(n), c(m);
    rep(i, n) cin >> a.at(i).first >> a.at(i).second;
    rep(i, m) cin >> c.at(i).first >> c.at(i).second;

    rep(i, n) {
        int md = 1001001001;
        int ans = -1;
        rep(j, m) {
            int d = abs(a.at(i).first - c.at(j).first) + abs(a.at(i).second - c.at(j).second);
            if(d < md) {
                md = d;
                ans = j;
            }
        }
        cout << ans + 1 << endl;
    }
    return 0;
}