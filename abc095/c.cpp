#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int c;
    P a,b;
    cin >> a.first >> b.first >> c >> a.second >> b.second;

    if (a.first + b.first <= 2*c) {
        cout << a.first * a.second + b.first * b.second << endl;
        return 0;
    }

    P l = a.second <= b.second ? a : b;
    P m = a.second <= b.second ? b : a;
    int ans = 2 * c * l.second;

    if (m.first <= 2*c) {
        ans += m.first * (m.second - l.second);
    }
    else {
        ans += 2 * c * (m.second - l.second);
    }
    cout << ans << endl;
    return 0;
}