#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
vector<vector<int>> ptn;
int n;

void f(int ni, int m, vector<int> p) {
    if (ni == n) {
        ptn.push_back(p);
        return;
    }
    for (int i = 0; i <= m+1; ++i) {
        vector<int> pi = p;
        pi.push_back(i);
        f(ni+1, max(m, i), pi);
    }
}

int main() {
    cin >> n;
    f(1, 0, {0});
    for (auto p : ptn) {
        for (int pi : p) {
            char c = 'a' + pi;
            cout << c;
        }
        cout << endl;
    }
    return 0;
}