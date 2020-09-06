#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> t(n), x(n), y(n);
    rep(i, n) cin >> t.at(i) >> x.at(i) >> y.at(i);

    int xi = 0, yi = 0, ti = 0;
    rep(i, n) {
        int dx = abs(x.at(i) - xi);
        int dy = abs(y.at(i) - yi);
        int dt = t.at(i) - ti;
        if(dt < dx + dy || (dt - dx - dy)%2 != 0) {
            cout << "No" << endl;
            return 0;
        }
        xi = x.at(i);
        yi = y.at(i);
        ti = t.at(i);
    }
    cout << "Yes" << endl;
    return 0;
}