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

void ng() {
    cout << -1 << ' ' << -1 << endl;
    exit(0);
}

void write(int l, int r) {
    cout << l << ' ' << r << endl;
    exit(0);
}

int main() {
    string s;
    cin >> s;
    vector<int> abc(26);
    int n = s.size();
    if (n == 2) {
        if (s[0] == s[1]) {
            write(1, 2);
        }
        else ng();
        return 0;
    }
    rep(i,3) {
        int x = s[i] - 'a';
        abc[x]++;
        if (2 <= abc[x]) {
            write(1, 3);
        }
    }
    for (int i = 3; i < n; ++i) {
        int x = s[i] - 'a';
        int y = s[i-3] - 'a';
        abc[x]++;
        abc[y]--;
        if (2 <= abc[x]) {
            write(i-1, i+1);
            return 0;
        }
    }
    ng();
    return 0;
}