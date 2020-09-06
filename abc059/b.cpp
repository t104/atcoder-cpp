#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    string a, b;
    cin >> a >> b;
    if(a.size() > b.size()) {
        cout << "GREATER" << endl;
        return 0;
    }
    if(a.size() < b.size()) {
        cout << "LESS" << endl;
        return 0;
    }
    if(a.size() == b.size()) {
        rep(i, a.size()) {
            int ai = a.at(i) - '0';
            int bi = b.at(i) - '0';
            if(ai > bi) {
                cout << "GREATER" << endl;
                return 0;
            }
            if(ai < bi) {
                cout << "LESS" << endl;
                return 0;
            }
        }
        cout << "EQUAL" << endl;
    }
    return 0;
}