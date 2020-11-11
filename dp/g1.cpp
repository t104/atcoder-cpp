#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const int max_n = 100100;

int n, m;
vector<vector<int>> G;
vector<int> deg;
vector<int> dp(max_n);

int main() {
    cin >> n >> m;
    G.assign(n, vector<int>());
    deg.assign(n,0);
    rep(i,m) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        G.at(x).push_back(y);
        deg.at(y)++;
    }

    queue<int> que;
    rep(v,n) if (deg.at(v) == 0) que.push(v);

    while (!que.empty()) {
        int v = que.front(); que.pop();
        for (auto vi : G.at(v)) {
            --deg.at(vi);
            if (deg.at(v) == 0) {
                que.push(vi);
                chmax(dp.at(vi), dp.at(v) + 1);
            }
        }
    }

    int res = 0;
    rep(v,n) chmax(res, dp.at(v));
    cout << res << endl;
    return 0;
}