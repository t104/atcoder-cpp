#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll x = a * b;
    ll y = c - a - b;
    if (y < 0) {
        cout << "No" << endl;
        return 0;
    }
    if (4 * x < y * y) {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
    return 0;
}