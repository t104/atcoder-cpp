#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;
const int MX = 2e5 + 10;

int main() {
    int n;
    cin >> n;
    string t;
    cin >> t;
    string s = "110";
    ll ans = 1e10;

    if (t == "1") {
        ans *= 2;
        cout << ans << endl;
        return 0;
    }

    if (t == "0" || t == "11") {
        cout << ans << endl;
        return 0;
    }

    if (t == "01") {
        ans--;
        cout << ans << endl;
        return 0;
    }

    int r = 2 * (MX/3 + 1);
    stringstream ss;
    rep(i,r) ss << s;
    string u = ss.str();

    if (u.find(t) == string::npos) {
        cout << 0 << endl;
        return 0;
    }

    ll first = t.find(s);
    ll last = t.rfind(s);
    ll l = (last - first) / 3 + 1;
    if (0 < first) ++l;
    if (last != n-3) ++l;

    ans -= l;
    ans++;
    cout << ans << endl;

    return 0;
}