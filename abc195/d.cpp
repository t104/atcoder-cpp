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

const int MX = 1000005;

int n, m, q;
vector<P> obj;
vector<P> x;

ll solve() {
    int l, r;
    cin >> l >> r;
    --l, --r;
    ll ans = 0;
    priority_queue<int> que;

    int id = 0;
    rep(i,m) {
        if (l <= x[i].second && x[i].second <= r) continue;
        while (id < n && obj[id].first <= x[i].first) {
            que.push(obj[id].second);
            id++;
        }
        if (que.size()) {
            ans += que.top(); que.pop();
        }
    }
    return ans;
}

int main() {
    cin >> n >> m >> q;
    obj.resize(n);
    x.resize(m);

    rep(i,n) {
        cin >> obj[i].first >> obj[i].second;
    }
    sort(obj.begin(), obj.end(), [&](auto x, auto y){
        if (x.first == y.first) return y.second < x.second;
        return x.first < y.first;
    });

    rep(i,m) {
        cin >> x[i].first;
        x[i].second = i;
    }
    sort(x.begin(), x.end());

    rep(i,q) cout << solve() << endl;
    return 0;
}