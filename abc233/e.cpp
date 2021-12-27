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
    reverse(s.begin(), s.end());
    vector<int> x(n);
    rep(i,n) x[i] = s[i] - '0';
    ll sum = 0;
    rep(i,n) sum += x[i];
    string ans;
    ll now = sum;
    rep(i,n) {
        ans.push_back('0' + (now % 10));
        now /= 10;
        sum -= x[i];
        now += sum;
    }
    while (now) {
        ans.push_back('0' + (now % 10));
        now /= 10;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}

