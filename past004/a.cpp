#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,char>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;

int main() {
    vector<P> a(3);
    rep(i,3) {
        int ai;
        cin >> ai;
        a.at(i) = make_pair(ai, 'A' + i);
    }
    sort(a.begin(), a.end());
    cout << a.at(1).second << endl;
    return 0;
}