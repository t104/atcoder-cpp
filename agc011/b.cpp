#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    sort(a.begin(), a.end());

    int c = 0;
    ll w = 0;
    rep(i,n-1) {
        w += a.at(i);
        if ((ll) w * 2 < (ll)a.at(i+1)) c = i + 1;
    }
    cout << n - c << endl;
    return 0;
}