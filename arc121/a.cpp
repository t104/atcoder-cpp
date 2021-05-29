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
using P = pair<ll,ll>;

ll dist(P a, P b) {
    return max(abs(a.first - b.first), abs(a.second - b.second));
}

int main() {
    int n;
    cin >> n;
    vector<P> x(n), y(n), p(n);
    rep(i,n) {
        cin >> x[i].first >> y[i].first;
        x[i].second = i;
        y[i].second = i;
        p[i].first = x[i].first;
        p[i].second = y[i].first;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    vector<pair<ll,P>> a;
    rep(i,2) {
        rep(j,2) {
            ll dx = dist(p[x[n-1-i].second], p[x[j].second]);
            ll dy = dist(p[y[n-1-i].second], p[y[j].second]);
            a.emplace_back(dx, make_pair(x[n-1-i].second, x[j].second));
            a.emplace_back(dy, make_pair(y[n-1-i].second, y[j].second));
        }
    }
    sort(a.rbegin(), a.rend());
    int i = 2;
    set<P> st;
    rep(j,8) {
        P pi = a[j].second;
        if (pi.second < pi.first) swap(pi.first, pi.second);
        if (st.count(pi)) continue;
        i--;
        if (i == 0) {
            cout << a[j].first << endl;
            return 0;
        }
        st.insert(pi);
    }
    return 0;
}