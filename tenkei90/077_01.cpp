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
using P = pair<ll,ll>;

const int MX = 20010;
vector<P> d = {
    {1,0},
    {1,1},
    {0,1},
    {-1,1},
    {-1,0},
    {-1,-1},
    {0,-1},
    {1,-1}
};

vector<int> ans(MX);
vector<P> start(MX), goal(MX);
int n;
ll t;

int main() {
    cin >> n >> t;
    rep(i,n) cin >> start[i].first >> start[i].second;
    rep(i,n) cin >> goal[i].first >> goal[i].second;
    assert(n < 8);
    vector<int> to(n);
    rep(i,n) to[i] = i;
    do {
        bool ok = true;
        rep(i,n) {
            ans[i] = -1;
            rep(j,8) {
                ll x = start[i].first + d[j].first * t;
                ll y = start[i].second + d[j].second * t;
                if (goal[to[i]].first == x && goal[to[i]].second == y) {
                    ans[i] = j;
                    break;
                }
            }
            if (ans[i] == -1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "Yes" << endl;
            rep(i,n) cout << ans[i]+1 << ' ';
            cout << endl;
            return 0;
        }
    } while (next_permutation(to.begin(), to.end()));

    cout << "No" << endl;
    return 0;
}