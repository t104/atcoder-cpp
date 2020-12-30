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
using P = pair<ll,ll>;

int n,m;
vector<vector<P>> graph;

int main() {
    cin >> n >> m;
    graph.resize(n, vector<P>(n, make_pair(LINF, LINF)));
    rep(i,m) {
        int s, t;
        P p;
        cin >> s >> t >> p.first >> p.second;
        --s, --t;
        graph.at(s).at(t) = p;
        graph.at(t).at(s) = p;
    }

    vector<vector<P>> dp((1<<n), vector<P>(n, make_pair(LINF, 0LL)));
    dp.at(0).at(0) = make_pair(0,1);
    rep(flg, (1<<n)) {
        rep(vi,n) {
            rep(vj,n) {
                if ((flg>>vj)&1) continue;
                if (graph.at(vi).at(vj).first == LINF) continue;
                auto [d, cnt] = dp.at(flg).at(vi);
                d += graph.at(vi).at(vj).first;
                if (graph.at(vi).at(vj).second < d) continue;
                if (dp.at(flg|(1<<vj)).at(vj).first == d) {
                    dp.at(flg|(1<<vj)).at(vj).second += cnt;
                }
                if (d < dp.at(flg|(1<<vj)).at(vj).first) {
                    dp.at(flg|(1<<vj)).at(vj) = make_pair(d, cnt);
                }
            }
        }
    }
    auto [d, cnt] = dp.at((1<<n) - 1).at(0);

    if (cnt != 0) {
        printf("%lld %lld\n", d, cnt);
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}