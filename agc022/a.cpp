#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

const int MAX_N = 26;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<bool> exists(MAX_N, false);
    if (n < MAX_N) {
        rep(i,n) exists.at(s.at(i) - 'a') = true;
        char c;
        rep(i,MAX_N) {
            if (!exists.at(i)) {
                c = (char) 'a' + i;
                break;
            }
        }
        s.push_back(c);
        cout << s << endl;
        return 0;
    }

    for (int i = n-1; 0 <= i; --i) {
        char r = s.at(i);
        for (int j = n-1; i < j; --j) {
            if (r < s.at(j)) {
                string t = s.substr(0, i);
                t.push_back(s.at(j));
                cout << t << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}