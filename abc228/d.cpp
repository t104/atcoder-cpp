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

const int N = 1<< 20;
vector<ll> a(N, -1);

int main() {
    int q;
    cin >> q;
    set<int> available;
    rep(i, N) available.insert(i);
    while (q--) {
        int t;
        ll x;
        cin >> t >> x;
        int h = x % N;
        if (t == 1) {
            auto it = available.lower_bound(h);
            if (it == available.end()) {
                h = 0;
            }
            it = available.lower_bound(h);
            h = *it;
            a[h] = x;
            available.erase(it);
        } else {
            cout << a[h] << endl;
        }
    }
    return 0;
}

