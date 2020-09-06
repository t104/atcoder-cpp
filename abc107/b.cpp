#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) cin >> a.at(i);
    vector<int> dellist;

    rep(i, w) {
        bool del = true;
        rep(j, h) {
            if(a.at(j).at(i) == '#') {
                del = false;
                break;
            }
        }
        if(del) {
            dellist.push_back(i);
        }
    }

    rep(i, h) {
        string s = a.at(i);
        rep(j, dellist.size()) {
            s.erase(dellist.at(j) - j, 1);
        }
        if(s.find("#") != string::npos) cout << s << endl;
    }
    return 0;
}