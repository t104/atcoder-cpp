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

int n;
string s, l, r;

void transform() {
    int t, a, b;
    cin >> t >> a >> b;
    --a, --b;
    if (t == 1) {
        if (a < n && b < n) swap(l[a], l[b]);
        else if (a < n) swap(l[a], r[b-n]);
        else if (b < n) swap(r[a-n], l[b]);
        else swap(r[a-n],r[b-n]);
    }
    else {
        swap(l,r);
    }
}

int main() {
    cin >> n >> s;
    l = s.substr(0,n);
    r = s.substr(n,n);
    int q;
    cin >> q;
    rep(i,q) transform();
    cout << l << r << endl;
    return 0;
}