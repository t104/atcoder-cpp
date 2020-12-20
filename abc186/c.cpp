#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;

int main() {
    int n;
    cin >> n;
    
    int ans = 0;
    vector<int> dig(7), eight(7);
    for (int i = 1; i <= n; ++i) {
        bool seven = false;
        dig.at(0)++;
        rep(j,5) {
            if (dig.at(j) == 10) {
                dig.at(j+1)++;
                dig.at(j) = 0;
            }
            if (dig.at(j) == 7) seven = true;
        }

        eight.at(0)++;
        rep(j,6) {
            if (eight.at(j) == 8) {
                eight.at(j+1)++;
                eight.at(j) = 0;
            }
            if (eight.at(j) == 7) seven = true;
        }

        if (!seven) {
            ans++;
            // cerr << i << endl;
        }
    }

    cout << ans << endl;
    return 0;
}