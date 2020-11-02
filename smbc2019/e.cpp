#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
using mint = modint1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    vector<int> colors(3);
    mint ans = 1;
    rep(i,n) {
        int count = 0;
        bool add = false;
        rep(j,3) {
            if (colors.at(j) == a.at(i)) {
                count++;
                if (!add) {
                    colors.at(j)++;
                    add = true;
                }
            }
        }
        ans *= count;
    }
    cout << ans.val() << endl;
    return 0;
}