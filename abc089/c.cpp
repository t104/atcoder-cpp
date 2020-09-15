#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    map<char, int> mp;
    vector<char> march = {'M', 'A', 'R', 'C', 'H'};
    for (char c : march) mp[c] = 0;
    rep(i,n) {
        string s;
        cin >> s;
        mp[s.at(0)]++;
    }

    ll ans = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            for (int k = j + 1; k < 5; ++k) {
                ans += (ll) mp.at(march.at(i)) * mp.at(march.at(j)) * mp.at(march.at(k));
            }
        }
    }
    cout << ans << endl;
    return 0;
}