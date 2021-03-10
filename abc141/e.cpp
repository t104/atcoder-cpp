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

vector<int> my_z_algorithm(string s) {
    int n = s.size();
    vector<int> z(n);
    int i = 1, len = 0;
    while (i < n) {
        while (i+len < n && s[len] == s[i+len]) len++;
        z[i] = len;
        if (len == 0) {
            i++;
            continue;
        }
        int k = 1;
        while (k < len && k + z[k] < len) {
            z[i+k] = z[k];
            k++;
        }
        i += k;
        len -= k;
    }
    return z;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    rep(i,n) {
        string t = s.substr(i,n-i);
        vector<int> v = my_z_algorithm(t);
        for (int j = 1; j < v.size(); ++j) {
            chmax(ans, min(j, v[j]));
        }
    }
    cout << ans << endl;
    return 0;
}