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

int main() {
    int n;
    cin >> n;
    vector<ll> s(n), t(n);
    rep(i,n) cin >> s[i];
    rep(i,n) cin >> t[i];
    priority_queue<P, vector<P>, greater<P>> que;
    rep(i,n) que.emplace(t[i], i);
    while (que.size()) {
        auto [tm, p] = que.top(); que.pop();
        int next = (p + 1) % n;
        if (chmin(t[next], tm + s[p])) {
            que.emplace(tm + s[p], next);
        }
    }
    rep(i,n) cout << t[i] << endl;
    return 0;
}

