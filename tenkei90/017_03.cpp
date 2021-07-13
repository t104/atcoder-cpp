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
    int n, m;
    cin >> n >> m;
    vector<int> l(m), r(m);
    rep(i,m) {
        cin >> l[i] >> r[i];
        l[i]--, r[i]--;
    }
    fenwick_tree<int> bit(n);
    vector<P> edges(m);
    rep(i,m) edges[i] = make_pair(r[i], l[i]);
    sort(edges.begin(), edges.end());
    ll ans = 0;
    auto get = [&](int p) {
        return bit.sum(0, p+1);
    };
    auto add = [&](int l, int r) {
        bit.add(l, 1);
        bit.add(r, -1);
    };
    queue<P> que;
    int prev = -1;
    rep(i,m) {
        if (prev != edges[i].first) {
            while (que.size()) {
                auto [ri, li] = que.front(); que.pop();
                add(li + 1, ri);
            }
        }
        ans += get(edges[i].second);
        que.push(edges[i]);
        prev = edges[i].first;
    }
    // vector<int> sum(n);
    // rep(i,m) {
    //     ans += sum[edges[i].second];
    //     for (int j = edges[i].second + 1; j < edges[i].first; ++j) {
    //         sum[j]++;
    //     }
    // }
    cout << ans << endl;
    return 0;
}