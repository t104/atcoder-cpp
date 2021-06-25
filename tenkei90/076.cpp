#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define INF 1001001001
#define LINF (1LL << 60)
#define rep(i, n) for(int i = 0; i < (n); ++i)
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}
template <typename T1, typename T2, typename T3>
inline bool in(T1 val, T2 l, T3 r) {
    return l <= val && val < r;
}
using ll = long long;
using ld = long double;
using P = pair<int, int>;

void ok() {
    cout << "Yes" << endl;
    exit(0);
}

void ng() {
    cout << "No" << endl;
    exit(0);
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll tot = 0;
    rep(i, n) tot += a[i];
    if(tot % 10)
        ng();

    auto search = [&](ll target) {
        int r = 0;
        ll vol = 0;
        rep(l, n) {
            while(r < n && vol < target) {
                vol += a[r];
                r++;
            }
            if(vol == target)
                ok();
            vol -= a[l];
        }
        if(vol == target)
            ok();
    };

    search(tot / 10);
    search(tot - tot / 10);

    ng();
    return 0;
}