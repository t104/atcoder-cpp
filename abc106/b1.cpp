#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

const int max_n = 205;

int main() {
    int n;
    cin >> n;

    vector<int> count(max_n);
    for (int i = 1; i < max_n; i+=2) {
        for (int j = 1; i*j < max_n; j+=2) {
            count[i*j]++;
        }
    }

    int ans = 0;
    rep(i,n+1) {
        if (count[i] == 8) ans++;
    }
    cout << ans << endl;
    return 0;
}