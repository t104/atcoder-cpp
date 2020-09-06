#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

bool isOk(string s) {
    if(s.size() % 2 == 1) return false;
    rep(i, s.size()/2) {
        if(s.at(i) != s.at(i + s.size()/2)) return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    for(int i = 1; i < s.size(); i++) {
        string t = s.substr(0, s.size() - i);
        if(isOk(t)) {
            cout << t.size() << endl;
            return 0;
        }
    }
    return 0;
}