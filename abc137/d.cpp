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
    int n, m;
    cin >> n >> m;
    vector<P> jobs(n);
    rep(i,n){
        cin >> jobs[i].first >> jobs[i].second;
    }
    sort(jobs.begin(), jobs.end());

    int l = 0;
    ll ans = 0;
    priority_queue<int> que;
    for (int i = m; 0 <= i; --i) {
        int mx = 0;
        while (jobs[l].first <= m-i && l < n) {
            que.push(jobs[l].second);
            ++l;
        }
        if (que.size()) {
            ans += que.top();
            que.pop();
        }
    }
    cout << ans << endl;
    return 0;
}