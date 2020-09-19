#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    stringstream ss;
    int n = s.size();
    vector<int> countx(1);
    rep(i, n) {
        if (s.at(i) == 'x') {
            countx.back()++;
        }
        else {
            ss << s.at(i);
            countx.push_back(0);
        }
    }
    string x = ss.str();
    reverse(x.begin(), x.end());
    
    if (ss.str() != x) {
        cout << -1 << endl;
        return 0;
    }
    
    int ans = 0;
    rep(i, countx.size()) {
        ans += abs(countx.at(i) - countx.at(countx.size()-1-i));
    }
    cout << ans/2 << endl;
    return 0;
}