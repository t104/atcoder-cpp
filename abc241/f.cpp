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

struct item {
    int h, w, steps;
    item(int h, int w, int steps): h(h), w(w), steps(steps) {}
};

int main() {
    int h, w, n, sh, sw, gh, gw;
    cin >> h >> w >> n >> sh >> sw >> gh >> gw;
    vector<int> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    map<int,set<int>> lateral, vertical;
    rep(i,n) {
        lateral[x[i]].insert(y[i]);
        vertical[y[i]].insert(x[i]);
    }
    map<P, int> dp;
    queue<item> que;
    que.emplace(sh, sw, 0);
    dp[make_pair(sh, sw)] = 0;
    while (que.size()) {
        auto [ch, cw, cs] = que.front(); que.pop();
        vector<P> nexts;
        if (lateral.count(ch)) {
            auto itr = lateral[ch].lower_bound(cw);
            if (itr != lateral[ch].end()) {
                nexts.emplace_back(ch, *itr - 1);
            }
            if (itr != lateral[ch].begin()) {
                itr--;
                nexts.emplace_back(ch, *itr + 1);
            }
        }
        if (vertical.count(cw)) {
            auto itr = vertical[cw].lower_bound(ch);
            if (itr != vertical[cw].end()) {
                nexts.emplace_back(*itr - 1, cw);
            }
            if (itr != vertical[cw].begin()) {
                itr--;
                nexts.emplace_back(*itr + 1, cw);
            }
        }
        for (auto p : nexts) {
            if (dp.count(p) == 0) {
                dp[p] = cs + 1;
                que.emplace(p.first, p.second, cs + 1);
            }
        }
    }
    P goal = make_pair(gh, gw);
    if (dp.count(goal)) {
        cout << dp[goal] << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}

