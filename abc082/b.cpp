#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s, t;
    cin >> s >> t;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());
    int n = s.size(), m = t.size();
    rep(i,m) {
        if (i == n || s.at(i) < t.at(i)) {
            cout << "Yes" << endl;
            return 0;
        }
        if(t.at(i) < s.at(i)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}