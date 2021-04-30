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
    ll n;
    cin >> n;
    vector<ll> ans;
    for (ll i = 1; i*i <= n; ++i) {
        if (n%i == 0) {
            ans.push_back(i);
            if (n/i != i) {
                ans.push_back(n/i);
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (auto ai: ans) cout << ai << endl;
    return 0;
}