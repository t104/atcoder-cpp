#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a.at(i);
        a.at(i) *= 2;
    }

    vector<ll> dam(n);
    ll dn = a.at(0) - a.at(n-1);
    for (int i = 1; i < n-1; ++i) {
        dn = a.at(i) - dn;
    }
    dn /= 2;
    dam.at(0) = a.at(n-1) - dn;
    dam.at(n-1) = dn;
    for (int i = 1; i < n-1; ++i) {
        dam.at(i) = a.at(i-1) - dam.at(i-1);
    }
    rep(i,n) {
        cout << dam.at(i);
        if (i < n-1) cout << ' ';
    }
    cout << endl;
    return 0;
}