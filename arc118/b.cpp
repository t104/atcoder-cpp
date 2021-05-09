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
using P = pair<ll,int>;

void print_ans(vector<ll> &ans) {
    for (auto ai: ans) cout << ai << ' ';
    cout << endl;
    exit(0);
}

int main() {
    int k;
    ll n, m;
    cin >> k >> n >> m;
    vector<ll> a(k), b(k);
    priority_queue<P, vector<P>, greater<P>> que;
    rep(i,k) cin >> a[i];

    auto f = [&](ll ai, ll bi){
        return abs(bi*n-ai*m);
    };

    rep(i,k) {
        b[i] = a[i]*m/n;
        if (f(a[i]+1LL, b[i]) < f(a[i], b[i])) {
            b[i]++;
        }
        que.emplace(b[i]*n-a[i]*m, i);
    }

    ll dif = m;
    rep(i,k) {
        dif -= b[i];
    }

    while (dif) {
        auto [d, i] = que.top(); que.pop();
        b[i]++;
        d = b[i]*n-a[i]*m;
        que.emplace(d, i);
        dif--;
    }

    rep(i,k) {
        cout << b[i] << ' ';
    }
    cout << endl;
    
    return 0;
}