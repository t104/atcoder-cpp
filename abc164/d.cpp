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

const int MX = 200005;
const int mod = 2019;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> now(mod), next(mod);
    int ans = 0;
    rep(i,n) {
        rep(j,mod) {
            next[(j*10 + (s[i]-'0'))%mod] = now[j];
        }
        rep(j,mod) {
            now[j] = next[j];
        }
        now[s[i] - '0']++;
        ans += now[0];
    }

    cout << ans << endl;
    return 0;
}