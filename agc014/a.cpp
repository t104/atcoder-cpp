#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

bool isEven(vector<int> vt) {
    bool even = true;
    rep(i, vt.size()) {
        even = even && vt.at(i) % 2 == 0;
    }
    return even;
}

int main() {
    vector<int> c(3);
    rep(i, 3) cin >> c.at(i);

    if(!isEven(c)) {
        cout << 0 << endl;
        return 0;
    }

    if(c.at(0) == c.at(1) && c.at(1) == c.at(2)) {
        cout << -1 << endl;
        return 0;
    }
    
    int ans = 0;
    while(isEven(c)) {
        vector<int> ci = {
            (c.at(1) + c.at(2)) /2,
            (c.at(0) + c.at(2)) / 2,
            (c.at(0) + c.at(1)) / 2
        };
        c = ci;
        ans++;
    }
    cout << ans << endl;
    return 0;
}