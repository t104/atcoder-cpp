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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    sort(b.begin(), b.end());
    set<int> candidates;
    vector<int> ans;
    rep(i,n) {
        candidates.insert(a[0] ^ b[i]);
    }
    for (auto &i: candidates) {
        vector<int> x(n);
        rep(j,n) x[j] = a[j] ^ i;
        sort(x.begin(), x.end());
        bool ok = true;
        rep(j,n) {
            if (x[j] != b[j]) {
                ok = false;
            }
        }
        if (ok) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (auto &i: ans) cout << i << endl;
    return 0;
}