#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<P> drinks(n);
    rep(i, n) cin >> drinks.at(i).first >> drinks.at(i).second;
    sort(drinks.begin(), drinks.end());
    ll amount = 0;
    int count = 0;
    rep(i, n) {
        int c = min(m - count, drinks.at(i).second);
        amount += (ll) c * drinks.at(i).first;
        count += c;
        if (count == m) break;
    }
    cout << amount << endl;
    return 0;
}