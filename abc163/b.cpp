#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    ll n;
    int m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i,m) cin >> a.at(i);
    ll sum = 0;
    rep(i,m) sum += a.at(i);
    if(sum <= n) cout << n-sum << endl;
    else cout << -1 << endl;
    return 0;
}