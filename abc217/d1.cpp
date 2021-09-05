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
    int L, Q;
    cin >> L >> Q;
    set<int> edges;
    edges.insert(0);
    edges.insert(L);
    while (Q--) {
        int c, x;
        cin >> c >> x;
        if (c == 1) {
            edges.insert(x);
        } else {
            auto it = edges.lower_bound(x);
            int r = *it;
            int l = *prev(it);
            cout << r-l << endl;
        }
    }
    return 0;
}