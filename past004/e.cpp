#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    sort(t.begin(), t.end());
    do {
        bool same = true;
        rep(i,n) {
            if (s.at(i) != t.at(i)) same = false;
        }
        if (same) continue;
        same = true;
        rep(i,n) {
            if (s.at(i) != t.at(n-1-i)) same = false;
        }
        if (same) continue;
        cout << t << endl;
        return 0;
    } while (next_permutation(t.begin(), t.end()));
    cout << "None" << endl;
    return 0;
}