#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    int sn = s.size();

    int r = -1;
    vector<string> words = {"dreamer", "dream", "eraser", "erase"};

    while (r < sn-1) {
        int now = r;
        for (auto word : words) {
            int n = word.size();
            string sub = s.substr(r+1, n);
            if (word == sub) {
                if (r+n == sn-1) {
                    cout << "YES" << endl;
                    return 0;
                }
                if (s.at(r+n+1) == 'd' || s.at(r+n+1) == 'e') {
                    r += n;
                    break;
                }
            }
        }
        if (now == r) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}