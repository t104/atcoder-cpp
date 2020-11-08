#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const int max_v = 100005;
const ll LINF = 1LL<<60;

int main() {
    int N, W;
    cin >> N >> W;
    vector<ll> weight(N), value(N);
    rep(i,N) cin >> weight.at(i) >> value.at(i);
    vector<vector<ll>> dp(N+1, vector<ll>(max_v, LINF));
    dp.at(0).at(0) = 0;
    rep(i,N) {
        for (int v = 0; v < max_v; ++v) {
            if (0 <= v - value.at(i))
                chmin(dp.at(i+1).at(v), dp.at(i).at(v - value.at(i)) + weight.at(i));
            
            chmin(dp.at(i+1).at(v), dp.at(i).at(v));
        }
    }
    for (int i = max_v - 1; 0 <= i; --i) {
        if (dp.at(N).at(i) <= W) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}