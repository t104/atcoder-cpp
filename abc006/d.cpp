#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define INF 1001001001
#define LINF (1LL<<60)
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    
    vector<int> dp;
    for (auto ai : a) {
        auto itr = lower_bound(dp.begin(), dp.end(), ai);
        if (itr == dp.end()) {
            dp.push_back(ai);
        }
        else {
            *itr = ai;
        }
    }

    int ans = n - dp.size();
    cout << ans << endl;
    return 0;
}