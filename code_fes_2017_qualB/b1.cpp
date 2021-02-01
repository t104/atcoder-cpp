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
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    map<int,int> mp;
    rep(i,n) {
        int d;
        cin >> d;
        mp[d]++;
    }
    int m;
    cin >> m;
    vector<int> t(m);
    rep(i,m) cin >> t[i];
    rep(i,m) {
        if (mp.count(t[i]) && 0 < mp.at(t[i])) {
            mp.at(t[i])--;
        }
        else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}