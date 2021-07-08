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
    int n;
    string s;
    cin >> n >> s;
    vector<int> circle, cross;
    rep(i,n) {
        if (s[i] == 'o') circle.push_back(i);
        else cross.push_back(i);
    }
    ll ans = 0;
    rep(i,n) {
        int r = -1;
        if (s[i] == 'o') {
            auto itr = lower_bound(cross.begin(), cross.end(), i+1);
            if (itr == cross.end()) continue;
            r = *itr;
        }
        else {
            auto itr = lower_bound(circle.begin(), circle.end(), i+1);
            if (itr == circle.end()) continue;
            r = *itr;
        }
        ans += n - r;
    }

    cout << ans << endl;

    return 0;
}