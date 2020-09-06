#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    map<char, int> mp;
    string w;
    cin >> w;

    for(char c : w) {
        if(mp.count(c)) {
            mp.at(c)++;
        }
        else {
            mp[c] = 1;
        }
    }
    for(auto m : mp) {
        if(m.second % 2 != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}