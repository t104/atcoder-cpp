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
    vector<int> ans;
    set<int> a, b;
    rep(i,n) {
        int ai;
        cin >> ai;
        a.insert(ai);
    }
    rep(i,m) {
        int bi;
        cin >> bi;
        b.insert(bi);
    }
    for (auto ai: a) {
        if (b.count(ai) == 0) ans.push_back(ai);
    }
    for (auto bi: b) {
        if (a.count(bi) == 0) ans.push_back(bi);
    }
    sort(ans.begin(), ans.end());
    for (auto ai: ans) cout << ai << ' ';
    cout << endl;
    return 0;
}