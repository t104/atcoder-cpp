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

void dame() {
    cout << -1 << endl;
    exit(0);
}

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    ll ans = 0;
    queue<int> ques, quet;
    rep(i,n) {
        if (t[i] == '1') quet.push(i);
        if (s[i] == '1') {
            if (!quet.empty()) {
                ans += i-quet.front(); quet.pop();
            }
            else ques.push(i);
        }
    }
    if (quet.size() || ques.size()%2) dame();
    while (ques.size()) {
        ll fi = ques.front(); ques.pop();
        ll sc = ques.front(); ques.pop();
        ans += sc - fi;
    }
    cout << ans << endl;
    return 0;
}