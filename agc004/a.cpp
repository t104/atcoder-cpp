#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    vector<ll> a(3);
    rep(i, 3) cin >> a.at(i);
    bool even = false;
    rep(i, 3) if (a.at(i) % 2 == 0) even = true;
    sort(a.begin(), a.end());

    if (even) cout << 0 << endl;
    else cout << a.at(0) * a.at(1) << endl;
    return 0;
}