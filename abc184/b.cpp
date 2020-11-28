#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;

    rep(i,n) {
        if (s[i] == 'o') x++;
        else if (0 < x) x--;
    }
    cout << x << endl;
    return 0;
}