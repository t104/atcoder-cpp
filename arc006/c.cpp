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
    int ans = 0;
    vector<vector<int>> w(n+1);
    rep(i,n) {
        int wi;
        cin >> wi;
        sort(w[i].begin(), w[i].end());
        for (auto &wj: w[i]) {
            if (0 < wi && wi <= wj) {
                w[i+1].push_back(wi);   
                wi = -1;
            }
            else w[i+1].push_back(wj);
        }
        if (0 < wi) w[i+1].push_back(wi);
    }
    cout << w[n].size() << endl;

    return 0;
}

