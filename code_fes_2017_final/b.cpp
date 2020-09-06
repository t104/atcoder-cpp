#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    map<char, int> mp;
    mp['a'] = 0;
    mp['b'] = 0;
    mp['c'] = 0;
    for (auto c : s) mp[c]++;
    bool ok = true;
    if (n <= 3) {
        for (auto p : mp) {
            if (2 <= p.second) ok = false;
        }
    }
    if (1 < abs(mp.at('a') - mp.at('b'))) ok = false;
    if (1 < abs(mp.at('b') - mp.at('c'))) ok = false;
    if (1 < abs(mp.at('c') - mp.at('a'))) ok = false;

    
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}