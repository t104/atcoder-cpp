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
using P = pair<int,int>;

int n;
vector<int> a, b, p;

void checkA(){
    rep(i,n-1) {
        assert(a[i] < a[i+1]);
    }
}

void checkB() {
    rep(i,n-1) {
        assert(b[i+1] < b[i]);
    }
}

void checkAB() {
    rep(i,n-1) {
        ll s0 = (ll) a[p[i]] + b[p[i]];
        ll s1 = (ll) a[p[i+1]] + b[p[i+1]];
        assert(s0 < s1);
    }
}

int main() {
    cin >> n;
    a.resize(n);
    b.resize(n);
    p.resize(n);

    rep(i,n) {
        cin >> p[i];
        --p[i];
    }
    
    rep(i,n) {
        a[p[i]] = 30000*(p[i] + 1);
        b[p[i]] = 30000 * (n-(p[i] + 1)) + (i+1);
    }

    rep(i,n) {
        cout << a[i];
        if (i < n-1) cout << ' ';
        else cout << endl;
    }
    rep(i,n) {
        cout << b[i];
        if (i < n-1) cout << ' ';
        else cout << endl;
    }

    checkA();
    checkB();
    checkAB();

    return 0;
}