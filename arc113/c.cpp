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
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;
    vector<int> dict(26);
    for (int i = n-1; 0 <= i; --i) {
        if (s[i] == s[i-1]) {
            ans += n-(i+1);
            ans -= dict[s[i]-'a'];
            rep(j,26) dict[j] = 0;
            dict[s[i]-'a'] = n-(i+1);
        }
        dict[s[i]-'a']++;
    }
    cout << ans << endl;
    return 0;
}