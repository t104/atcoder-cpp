#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    bool isInt = true;
    for(char c : s) isInt = isInt && '0' <= c && c <= '9';
    if(isInt){
        int n = stoi(s);
        cout << 2*n << endl;
    } else {
        cout << "error" << endl;
    }
    return 0;
}