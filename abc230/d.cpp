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
    int n, d;
    cin >> n >> d;
    vector<P> range(n);
    rep(i,n) cin >> range[i].second >> range[i].first;
    sort(range.begin(), range.end());
    vector<int> r;
    rep(i,n) {
        auto p = lower_bound(r.begin(), r.end(), range[i].first);
        if (p != r.end() && *p - range[i].first < d) continue;
        auto q = lower_bound(r.begin(), r.end(), range[i].second);
        if (q != r.end() && *q - range[i].first < d) continue;
        r.push_back(range[i].first + d - 1);
    }
    cout << r.size() << endl;
    return 0;
}

