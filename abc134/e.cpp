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
using P = pair<int,int>;

vector<int> dp;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];                                           

    deque<int> d;
    rep(i,n) {
        int p = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (p == 0) {
            d.push_front(a[i]);
        }
        else {
            d[p-1] = a[i];
        }
    }
    int ans = d.size();
    cout << ans << endl;
    return 0;
}