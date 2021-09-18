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
    vector<int> abc(30);
    for (auto &c: s) {
        abc[c-'a']++;
    }
    int n = s.size();
    int odds = 0;
    for (auto i: abc) odds += i%2;
    if (odds == 0) {
        cout << n << endl;
        return 0;
    }
    cout << 2 * ((n-odds) / (2*odds)) + 1 << endl;
    return 0;
}

