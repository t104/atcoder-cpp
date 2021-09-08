/**
 * Submition https://atcoder.jp/contests/abc214/submissions/25014356
**/

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

void solve() {
    int n;
    cin >> n;
    vector<P> p(n);
    rep(i,n) cin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end());
    priority_queue<int, vector<int>, greater<int>> q;
    int x = 1;
    p.emplace_back(INF, INF);
    for (auto [l, r]: p) {
        while (x < l && q.size()) {
            if (q.top() < x) {
                cout << "No" << endl;
                return;
            }
            q.pop();
            ++x;
        }
        x = l;
        q.push(r);
    }
    cout << "Yes" << endl;
}

int main() {
    int T;
    cin >> T;
    rep(ti, T) solve();
    return 0;
}