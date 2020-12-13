#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;

struct mura{
    int h, d;
    vector<int> from;
    mura(int h = 0) : h(h), d(INF) {}
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<mura> g(n);
    rep(i,n) cin >> g.at(i).h;
    vector<int> evacuate(k);
    rep(i,k) {
        int c;
        cin >> c;
        --c;
        evacuate.at(i) = c;
        g.at(c).d = 0;
    }

    rep(i,m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (g.at(a).h < g.at(b).h) g.at(a).from.push_back(b);
        else g.at(b).from.push_back(a);
    }

    queue<P> que;
    rep(i,k) {
        que.emplace(0, evacuate.at(i));
    }

    while (!que.empty()) {
        auto [d, v] = que.front(); que.pop();
        
        if (g.at(v).d < d) continue;
        for (auto nv : g.at(v).from) {
            int nd = d+1;
            if (g.at(nv).d <= nd) continue;
            g.at(nv).d = nd;
            que.emplace(nd, nv);
        }
    }

    rep(i,n) {
        if (g.at(i).d == INF) {
            cout << -1 << endl;
        }
        else {
            cout << g.at(i).d << endl;
        }
    }
    return 0;
}