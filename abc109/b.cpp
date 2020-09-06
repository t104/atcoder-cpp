#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<string> w(n);
    rep(i,n) cin >> w.at(i);
    set<string> dict;
    
    rep(i, n) {
        if(dict.count(w.at(i))) {
            cout << "No" << endl;
            return 0;
        }
        if(0 < i) {
            char last = w.at(i-1)[w.at(i-1).size()-1];
            char first = w.at(i)[0];
            if(last != first) {
                cout << "No" << endl;
                return 0;
            }
        }
        dict.insert(w.at(i));
    }
    cout << "Yes" << endl;
    return 0;
}