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

int grid[100][100];
ll n, a, b, p, q, r, s;

bool ok1(ll k) {
    return max(1-a, 1-b) <= k && k <= min(n-a, n-b);
}

bool ok2(ll k) {
    return max(1-a, b-n) <= k && k <= min(n-a, b-1);
}

int main() {
    cin >> n >> a >> b >> p >> q >> r >> s;
    ll h = q - p + 1;
    ll w = s - r + 1;
    rep(i,h) {
        rep(j,w) {
            bool black = false;
            ll x = p + i;
            ll y = r + j;
            if (x-a == y-b && ok1(x-a)) {
                black = true;
            }
            if (x+y == a+b && ok2((x-y-a+b)/2)) {
                black = true;
            }
            cout << (black ? '#' : '.');
        }
        cout << endl;
    }
    return 0;
}

