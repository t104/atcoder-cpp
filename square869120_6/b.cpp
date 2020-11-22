#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

const ll LINF = 1LL<<60;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a.at(i) >> b.at(i);
    vector<int> all;
    rep(i,n) {
        all.push_back(a[i]);
        all.push_back(b[i]);
    }
    sort(all.begin(), all.end());

    ll ans = LINF;
    rep(i,2*n) {
        for (int j = i+1; j < 2*n; ++j) {
            ll sum = 0;
            rep(k,n) {
                sum += abs(a[k] - all[i]);
                sum += abs(b[k] - a[k]);
                sum += abs(all[j] - b[k]);
            }
            chmin(ans, sum);
        }
    }

    cout << ans << endl;
    return 0;
}