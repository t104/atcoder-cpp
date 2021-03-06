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

void solve() {
    int n;
    cin >> n;
    vector<P> ranges(n);
    rep(i,n) cin >> ranges[i].first >> ranges[i].second;
    sort(ranges.begin(), ranges.end());
    int l = 0, i = 0;
    priority_queue<int, vector<int>, greater<int>> que;
    while (i < n || !que.empty()) {
        if (que.empty()) {
            l = ranges[i].first;
        }
        while (ranges[i].first == l) {
            que.push(ranges[i].second);
            i++;
        }
        if (que.top() < l) {
            cout << "No" << endl;
            return;
        } else {
            que.pop();
            l++;
        }
    }
    cout << "Yes" << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}

