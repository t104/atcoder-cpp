#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a.at(i);
    map<ll, queue<int>> p;
    rep(i, n) {
        p[a.at(i) + (i+1)].push(i);
    }

    ll count = 0;
    rep(i, n) {
        ll key = i + 1 - a.at(i);
        if(p.count(key)) {
            int size = p.at(key).size();
            count += size;
        }
    }

    cout << count << endl;
    return 0;
}
