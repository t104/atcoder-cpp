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
    int n;
    string s;
    cin >> n >> s;
    vector<char> t;
    for (char c : s) {
        if (c == 'A') {
            rep(_, 2) t.push_back('B');
        } else {
            t.push_back(c);
        }
    }
    string ans;
    for (int i = 0; i < (int) t.size(); ++i) {
        if (i+1 < t.size()) {
            if (t[i] == 'B' && t[i+1] == 'B') {
                ans.push_back('A');
                i++;
                continue;
            }
        }
        ans.push_back(t[i]);
    }
    cout << ans << endl;
    return 0;
}

