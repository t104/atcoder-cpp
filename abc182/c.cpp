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
    string s;
    cin >> s;
    int len = s.size();
    int r = 0;
    vector<int> residue(3);
    for (auto c : s) {
        int x = c - '0';
        r += x;
        r %= 3;
        residue.at(x%3)++;
    }
    if (r == 0) {
        cout << 0 << endl;
        return 0;
    }
    if (r == 1) {
        int ans = -1;
        if (1 < len && 0 < residue.at(1)) ans = 1;
        else if (2 < len && 2 <= residue.at(2)) ans = 2;
        cout << ans << endl;
        return 0;
    }
    int ans = -1;
    if (1 < len && 0 < residue.at(2)) ans = 1;
    else if (2 < len && 2 <= residue.at(1)) ans = 2;
    cout << ans << endl;
    return 0;
}