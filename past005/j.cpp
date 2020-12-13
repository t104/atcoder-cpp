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
const ll MX = 1e15+10;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    ll x;
    cin >> x;
    vector<string> t;
    vector<ll> len;
    string now = "";
    rep(i,n) {
        if ('a' <= s.at(i) && s.at(i) <= 'z') {
            now.push_back(s.at(i));
            continue;
        }
        int l = s.at(i) = '0';
        t.push_back(now);
        now = "";
        len.push_back(l);
    }

    return 0;
}