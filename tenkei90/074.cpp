#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define INF 1001001001
#define LINF (1LL<<60)
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){ return a > b && (a = b, true); }
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){ return a < b && (a = b, true); }
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using ld = long double;
using P = pair<int,int>;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n);
    rep(i,n) a[i] = s[i] - 'a';
    auto f = [&](int i) {
        a[i]--;
        rep(j,i) {
            a[j] = (a[j] + 1) % 3;
        }
    };
    ll ans = 0;
    bool ok = true;
    while (ok) {
        ok = false;
        rep(i,n) {
            if (a[i] == 0) continue;
            ok = true;
            ans++;
            f(i);
            rep(j,n) cout << a[j];
            cout << endl;
            break;
        }
    }
    // rep(i,n) {
    //     if (a[i] == 1) ans += 1LL << i;
    //     if (a[i] == 2) ans += 1LL << (i+1);
    // }
    cout << ans << endl;
    return 0;
}