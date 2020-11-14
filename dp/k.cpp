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
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);

    vector<bool> dp(2*k, false);
    rep(i,k) rep(j,n) {
        if (!dp.at(i)) dp.at(i + a.at(j)) = true;
    }
    if (dp.at(k)) {
        cout << "First" << endl;
    }
    else {
        cout << "Second" << endl;
    }
    return 0;
}