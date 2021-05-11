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

/**
 * 略解
 * ====================
 * 前から i 番目の文字は答えになる文字列の i-n+k 番目以降の文字になりうる。
 * 答えになる文字列の i-n+k 番目以降の文字列に i 番目の文字より辞書順で後ろの文字があったら、
 * その文字を i 番目の文字にしてそれ以降を取り除く。
 * そうでなければ、k 文字になるまで答えになる文字列の最後に追加する。
**/


int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    string ans;
    rep(i,n) {
        int p = max(0, i-n+k);
        bool replace = false;
        for (int j = p; j < ans.size(); ++j) {
            if (s[i] < ans[j]) {
                ans = ans.substr(0, j+1);
                ans[j] = s[i];
                replace = true;
                break;
            }
        }
        if (!replace && ans.size() < k) ans.push_back(s[i]);
    }
    cout << ans << endl;
    return 0;
}