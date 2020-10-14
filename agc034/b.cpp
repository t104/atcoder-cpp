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
    int n = s.size();
    ll ans = 0;
    rep(i,n) {
        vector<int> a;
        while (i < n) {
            if (s.at(i) == 'A') a.push_back(1);
            else if (i+1 < n && s.at(i) == 'B' && s.at(i+1) == 'C') {
                a.push_back(0);
                i++;
            }
            else break;
            i++;
        }
        int sum = 0;
        for (int ai : a) {
            sum += ai;
            if (ai == 0) ans += sum;
        }
    }
    cout << ans << endl;
    return 0;
}