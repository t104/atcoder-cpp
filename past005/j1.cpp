#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<string,ll>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;
const ll MX = 1e15;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    ll x;
    cin >> x;
    
    vector<ll> cnt(n+1,0);
    for (int i = 0; i < n; ++i) {
        if ('0' < s[i] && s[i] <= '9') {
            cnt[i+1] = min(MX, cnt[i] * (s[i] - '0' + 1));
        }
        else {
            cnt[i+1] = min(MX, cnt[i] + 1);
        }
    }

    for (int i = n; 0 <= i; --i) {
        if (x <= cnt[i]) continue;
        if ('0' < s[i] && s[i] <= '9') {
            x = (x-1)%cnt[i] + 1;
        }
        else {
            cout << s[i] << endl;
            break;
        }
    }

    return 0;
}