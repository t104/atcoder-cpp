#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,string>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;
const string ambigous = "AMBIGUOUS";

int main() {
    int n, k;
    cin >> n >> k;
    --k;
    map<string,int> mp;
    rep(i,n) {
        string s;
        cin >> s;
        mp[s]++;
    }
    vector<P> vt;
    for (auto m : mp) {
        vt.push_back({m.second, m.first});
    }
    int vn = vt.size();
    sort(vt.rbegin(), vt.rend());
    if (0 <= k-1 && vt.at(k-1).first == vt.at(k).first) {
        cout << ambigous << endl;
        return 0;
    }
    if (k+1 < vn && vt.at(k).first == vt.at(k+1).first) {
        cout << ambigous << endl;
        return 0;
    }
    cout << vt.at(k).second << endl;
    return 0;
}