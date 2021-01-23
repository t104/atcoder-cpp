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
using P = pair<int,int>;

const int MX = 100000;

int main() {
    int n;
    cin >> n;
    vector<int> cnt(1,0);
    for (int i = 1; i*(i+1) <= 2*MX; ++i) {
        cnt.push_back(i*(i+1));
    }
    
    int m = cnt.size();
    n *= 2;
    int x = -1;
    rep(i,m) {
        if (cnt[i] == n) x = i;
    }

    if (x == -1) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    int y = n/x;
    cout << y << endl;

    vector<vector<int>> s(y);
    int k = 1;
    for (int i = 0; i < y; ++i) {
        for (int j = i+1; j <= i+x; ++j, ++k) {
            s[i].push_back(k);
            s[j].push_back(k);
        }
        --x;
    }

    x = s[0].size();
    rep(i,y) {
        cout << x << ' ';
        rep(j,x) {
            cout << s[i][j];
            if (j == x-1) cout << endl;
            else cout << ' ';
        }
    }

    return 0;
}