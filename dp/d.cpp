#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, W;
    cin >> N >> W;
    vector<ll> weight(N), value(N);
    rep(i,N) cin >> weight.at(i) >> value.at(i);
    vector<vector<ll>> dp(N+1, vector<ll>(W+1, 0));
    rep(i,N) {
        for (int w = 0; w <= W; ++w) {
            if (0 <= w - weight.at(i)) {
                chmax(dp.at(i+1).at(w), dp.at(i).at(w - weight.at(i)) + value.at(i));
            }

            chmax(dp.at(i+1).at(w), dp.at(i).at(w));
        }
    }
    cout << dp.at(N).at(W) << endl;
    return 0;
}