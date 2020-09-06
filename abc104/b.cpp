#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

bool isOk(string s) {
    if(s.at(0) != 'A') return false;
    int count = 0;
    for(int i = 1; i < s.size(); i++) {
        if('a' <= s.at(i) && s.at(i) <= 'z') continue;
        if(i < 2 || s.size() - 2 < i || s.at(i) != 'C') return false;
        count++;
    }
    return count == 1;
}

int main() {
    string s;
    cin >> s;

    if(isOk(s)) cout << "AC" << endl;
    else cout << "WA" << endl;
    return 0;
}