#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> t(n, vector<int>(n));
    rep(i,n) rep(j,n) cin >> t.at(i).at(j);
    vector<int> route(n-1);
    rep(i,n-1) route.at(i) = i+1;
    
    int ans = 0;
    do {
        int time = 0;
        time += t.at(0).at(route.at(0));
        rep(i,n-2) {
            time += t.at(route.at(i)).at(route.at(i+1));
        }
        time += t.at(route.at(n-2)).at(0);
        if (time == k) ans++;
    } while (next_permutation(route.begin(), route.end()));
    cout << ans << endl;
    return 0;
}