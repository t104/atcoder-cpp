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

ll pow(ll a, int x) {
    ll res = 1;
    rep(i,x) res *= a;
    return res;
}

int main() {
    int b;
    ll a, c;
    cin >> a >> b >> c;
    if (a < pow(c,b)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}