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
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;

    vector<P> all;
    for (int wa = 0; wa*100 < f; wa += a) {
        for (int wb = 0; (wa+wb)*100 < f; wb += b) {
            int smax = e*(wa+wb);
            int water = (wa+wb)*100;
            for (int sc = 0; sc <= smax; sc += c) {
                if (f < sc + water) continue;
                int r = min(smax-sc, f-sc-water);
                all.emplace_back(sc + r - r%d, water);
            }
        }
    }
    P ans = {0,100*a};
    for (auto p: all) {
        if (p.first + p.second != 0 &&
            ans.first * (p.first + p.second) < p.first * (ans.first + ans.second)) {
            ans = p;
        }
    }
    cout << ans.first + ans.second << ' ' << ans.first << endl;
    return 0;
}