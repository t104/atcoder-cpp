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
    map<char, int> mp;
    rep(i,10) mp['0'+i] = 0;
    for (auto c : s) mp[c]++;
    sort(s.begin(), s.end());
    if (s.size() < 4) {
        do {
            int n = stoi(s);
            if (n%8 == 0) {
                cout << "Yes" << endl;
                return 0;
            }
        } while (next_permutation(s.begin(), s.end()));
        cout << "No" << endl;
        return 0;
    }

    for (int i = 13; i*8 < 1000; ++i) {
        string si = to_string(i*8);
        map<char, int> eight;
        for (char c : si) eight[c]++;
        bool ok = true;
        for (auto e : eight) {
            if (mp.at(e.first) < e.second) ok = false;
        }
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}