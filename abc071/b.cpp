#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    map<char, bool> ab;
    string s;
    cin >> s;
    for(char c = 'a'; c <= 'z'; c++) {
        ab[c] = false;
    }
    for(char c : s) {
        ab[c] = true;
    }
    for(auto c : ab) {
        if(!c.second) {
            cout << c.first << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}