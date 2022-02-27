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
    int q;
    cin >> q;
    vector<int> t(q), k(q);
    vector<ll> x(q);
    rep(i,q) {
        cin >> t[i] >> x[i];
        if (t[i] != 1) {
            cin >> k[i];
        }
    }
    vector<ll> y = x;
    sort(y.begin(), y.end());
    y.erase(unique(y.begin(), y.end()), y.end());
    vector<int> compressed(q);
    rep(i,q) {
        compressed[i] = lower_bound(y.begin(), y.end(), x[i]) - y.begin();
    }
    multiset<int> st;
    rep(i,q) {
        if (t[i] == 1) {
            st.insert(compressed[i]);
        }
        if (t[i] == 2) {
            auto itr = st.upper_bound(compressed[i]);
            bool ok = true;
            rep(j,k[i]) {
                if (itr != st.begin()) {
                    itr--;
                } else {
                    ok = false;
                }
            }
            cout << (ok ? y[*itr] : -1) << endl;
        }
        if (t[i] == 3) {
            auto itr = st.lower_bound(compressed[i]);
            bool ok = true;
            rep(j,k[i]-1) {
                if (itr == st.end()) {
                    ok = false;
                } else {
                    itr++;
                }
            }
            if (itr == st.end()) ok = false;
            cout << (ok ? y[*itr] : -1) << endl;
        }
    }
    return 0;
}