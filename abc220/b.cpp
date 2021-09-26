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

ll to_decimal(string x, int k) {
    ll res = 0;
    for (auto c: x) {
        res *= k;
        res += c - '0';
    }
    return res;
}

int main() {
    int k;
    string a, b;
    cin >> k >> a >> b;
    ll ans = to_decimal(a, k) * to_decimal(b, k);
    cout << ans << endl;
    return 0;
}

