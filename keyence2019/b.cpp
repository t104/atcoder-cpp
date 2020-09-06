#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

bool isKeyence(string s) {
    string k = "keyence";
    int pos = s.find(k);
    if(pos != string::npos) {
        if(pos == 0 || pos + k.size() == s.size()) return true;
    }
    for(int i = 1; i < k.size(); i++) {
        string l = k.substr(0, k.size()-i);
        pos = s.find(l);
        if(pos != string::npos) {
            if(pos != 0) continue;
            string m = k.substr(l.size(), k.size()-l.size());
            string n = s.substr(s.size()-m.size(), s.size()-1);
            if(m == n) return true;
        }
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    if(isKeyence(s)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}