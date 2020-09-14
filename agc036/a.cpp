#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll e9 = 1000000000;

int main() {
    ll s;
    cin >> s;
    ll x1 = 0, y1 = 0;
    ll x2 = e9, y2 = 1;
    ll y3 = s / e9;
    if (0 < s % e9) y3++;
    ll x3 = y3 * e9 - s;
    cout << x1 << ' ' << y1 << ' ';
    cout << x2 << ' ' << y2 << ' ';
    cout << x3 << ' ' << y3;
    return 0;
}