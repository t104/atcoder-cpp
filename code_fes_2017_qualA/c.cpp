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
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a.at(i);
    map<char, int> mp;
    rep(i,h) rep(j,w) mp[a.at(i).at(j)]++;
    int g2 = 0;
    if (h%2 == 1) g2 += w/2;
    if (w%2 == 1) g2 += h/2;
    int g4 = h/2 * w/2;
    if ((h*w)%2 == 1) {
        for (auto& m : mp) {
            if (m.second % 2 == 1) {
                m.second--;
                break;
            }
        }
    }

    rep(i,g2) {
        for (auto& m : mp) {
            if (m.second % 4 == 2) {
                m.second -= 2;
                break;
            }
        }
    }

    rep(i,g4) {
        for (auto& m : mp) {
            if (0 < m.second && m.second % 4 == 0) {
                m.second -= 4;
                break;
            }
        }
    }
    for (auto& m : mp) {
        if (m.second%4 != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}