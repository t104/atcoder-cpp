#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int posa = -1, posz = -1;
    string s;
    cin >> s;
    rep(i, s.size()) {
        if(posa == -1 && s.at(i) == 'A') posa = i;
        if(s.at(i) == 'Z') posz = i;
    }
    cout << posz - posa + 1 << endl;
    return 0;
}