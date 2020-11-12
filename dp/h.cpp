#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using mint = modint1000000007;
using P = pair<int,int>;
const vector<P> d = {{1,0}, {0,1}};

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    rep(i,h) cin >> grid.at(i);
    vector<vector<pair<int,mint>>> dp(h, vector<pair<int,mint>>(w, {-1, 0}));
    dp.at(0).at(0) = {0, 1};

    queue<P> que;
    que.push({0,0});
    while (!que.empty()) {
        P now = que.front(); que.pop();
        int len = dp.at(now.first).at(now.second).first;
        mint count = dp.at(now.first).at(now.second).second;
        for (auto di : d) {
            int nh = now.first + di.first;
            int nw = now.second + di.second;
            if (0 <= nh && nh < h && 0 <= nw && nw < w && grid.at(nh).at(nw) == '.') {
                if (dp.at(nh).at(nw).first == -1) {
                    dp.at(nh).at(nw).first = len + 1;
                    dp.at(nh).at(nw).second += count;
                    que.push({nh, nw});
                }
                else if (dp.at(nh).at(nw).first == len + 1) {
                    dp.at(nh).at(nw).second += count;
                }
            }
        }
    }

    cout << dp.at(h-1).at(w-1).second.val() << endl;

    return 0;
}