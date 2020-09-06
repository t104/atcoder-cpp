#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    vector<int> pos;

    rep(i, s.size()) {
        if(s.at(i) == 'B') pos.push_back(i);
    }
    
    ll ans  = 0;
    rep(i, pos.size()) {
        ans += s.size() - pos.size() +i - pos.at(i);
    }

    cout << ans << endl;
    return 0;
}