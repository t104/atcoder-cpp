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

const int MX = 200010;


int main() {
    int n;
    cin >> n;
    vector<P> p(n);
    rep(i,n) cin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end());
    int l = 0, r = p[n-1].first - p[0].first;
    while (l+1 < r) {
        int m = (l+r) / 2;
        bool ok = true;
        rep(i,n) {
            auto itr = lower_bound(p.begin(), p.end(), make_pair(p[i].first + m, 0));
            if (itr == p.end()) break;
            while (itr != p.end()) {
                if (abs((*itr).first - p[i].first) <= m) {
                    itr++;
                    continue;
                }
                int d = abs((*itr).second - p[i].second);
                if (m < d) {
                    ok = false;
                    break;
                }
                itr++;
            }
        }
        if (ok) r = m;
        else l = m;
    }
    cout << r << endl;
    return 0;
}

