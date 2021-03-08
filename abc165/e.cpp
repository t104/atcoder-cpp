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

int n, m;

int main() {
    cin >> n >> m;
    vector<P> ans;
    if (n%2) {
        for (int l = 1, r = n-1; l < r; l++, r--) {
            ans.emplace_back(l,r);
        }
    }
    else {
        bool flag = false;
        for (int l = 1, r = n-1; l < r; l++, r--) {
            if (!flag && r-l <= n/2) {
                --r;
                flag = true;
            }
            ans.emplace_back(l,r);
        }
    }
    
    rep(i,m) printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}