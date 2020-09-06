#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    bool isSeven = false;
    for(char c : s){
        if(c == '7') isSeven = true;
    }
    if(isSeven) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}