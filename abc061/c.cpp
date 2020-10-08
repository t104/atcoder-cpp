#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

int main() {
    int n;
    ll k;
    cin >> n >> k;
    map<int, ll> mp;
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        if (mp.count(a)) mp.at(a) += b;
        else mp[a] = b;
    }
    for (auto p : mp) {
        if (k <= p.second) {
            cout << p.first << endl;
            return 0;
        }
        else k -= p.second;
    }
    return 0;
}