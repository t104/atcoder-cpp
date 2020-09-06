#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<string> s(n);
    vector<char> ans(n);
    rep(i, n) cin >> s.at(i);

    bool ok = true;

    auto next = [&](int i, int& x, int& y) {
        if(x + y == 0) {
            ok = false;
            return ok;
        }
        if(x == 0) {
            ans.at(i) = s.at(i).at(0);
            x++; y--;
        } else if (y == 0) {
            ans.at(i) = s.at(i).at(1);
            x--; y++;
        } else {
            if(i < n-1 && s.at(i+1).find(s.at(i).at(0)) != string::npos) {
                ans.at(i) = s.at(i).at(0);
                x++; y--;
            } else {
                ans.at(i) = s.at(i).at(1);
                x--; y++;
            }
        }
        return true;
    };

    rep(i, n) {
        if(s.at(i) == "AB") {
            if(!next(i, a, b)) break;
        } else if(s.at(i) == "AC") {
            if(!next(i, a, c)) break;
        } else if(s.at(i) == "BC") {
            if(!next(i, b, c)) break;
        }
    }

    if(ok) {
        cout << "Yes" << endl;
        rep(i, n) cout << ans.at(i) << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}