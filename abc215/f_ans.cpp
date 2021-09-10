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
    int n; cin >> n;
    vector<P> v(n);
    rep(i,n) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    int ok = 0, ng = INF;
    while (ng - ok > 1) {
        int md = (ok + ng) / 2;
        queue<P> que;
        bool able = false;
        int mi = INF, ma = 0;
        for (auto [xi, yi]: v) {
            while (!que.empty()) {
                auto [xj, yj] = que.front();
                // vはソートされているので、xj <= xi
                if (xj > xi - md) break;
                // xiからの距離がmd以下なら
                chmin(mi, yj);
                chmax(ma, yj);
                que.pop();
            }
            // y座標の最小値がyi-md以下、または最大値がyi+md以上なら
            // 距離mdが以上の点i, jが存在するからOK
            if (mi <= yi - md || ma >= yi + md) able = true;
            que.emplace(xi, yi);
        }
        if (able) ok = md;
        else ng = md;
    }
    cout << ok << endl;
    return 0;
}