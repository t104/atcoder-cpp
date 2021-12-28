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
    vector<string> words;
    string t;
    for (auto &c : s) {
        t.push_back(c);
        if (1 < t.size() && isupper(c)) {
            words.push_back(t);
            t.clear();
        }
    }
    sort(words.begin(), words.end(), [](string lhs, string rhs){
        transform(lhs.begin(), lhs.end(), lhs.begin(), ::tolower);
        transform(rhs.begin(), rhs.end(), rhs.begin(), ::tolower);
        return lhs < rhs;
    });
    for (auto &w : words) cout << w;
    cout << endl;
    return 0;
}

