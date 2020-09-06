#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    vector<int> count;
    vector<char> sign;
    sign.push_back(s.at(0));
    int ct = 0;
    for(char c : s) {
        if(c == sign.at(sign.size()-1)) ct++;
        else {
            count.push_back(ct);
            ct = 1;
            sign.push_back(c);
        }
    }
    count.push_back(ct);

    ll ans = 0;
    rep(i, count.size()) {
        ans += ((ll) count.at(i)*(count.at(i)+1))/2;
        if(i+1 < count.size() && sign.at(i) == '<') {
            if(count.at(i) <= count.at(i+1)) ans -= count.at(i);
            else ans -= count.at(i+1);
        }
    }
    cout << ans << endl;

    return 0;
}