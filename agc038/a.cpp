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
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    rep(i,b) {
        rep(j,a) cout << 0;
        rep(j,w-a) cout << 1;
        cout << endl;
    }
    rep(i,h-b) {
        rep(j,a) cout << 1;
        rep(j,w-a) cout << 0;
        cout << endl;
    }
    return 0;
}