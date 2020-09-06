#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    int pt1 = 0;
    int pt2 = 0;
    rep(i, s.size()) {
        if(i % 2 == 0) {
            if(s.at(i) == '0') pt1++;
            if(s.at(i) == '1') pt2++;
        }
        else {
            if(s.at(i) == '1') pt1++;
            if(s.at(i) == '0') pt2++;
        }
    }
    cout << min(pt1, pt2) << endl;
    return 0;
}