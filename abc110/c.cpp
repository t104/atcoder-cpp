#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    map<char, char> st, ts;
    rep(i,n) {
       if (st.count(s.at(i))) {
           if (st.at(s.at(i)) != t.at(i)) {
               cout << "No" << endl;
               return 0;
           }
       }
       else {
           st[s.at(i)] = t.at(i);
       }
       if (ts.count(t.at(i))) {
           if (ts.at(t.at(i)) != s.at(i)) {
               cout << "No" << endl;
               return 0;
           }
       }
       else {
           ts[t.at(i)] = s.at(i);
       }
    }
    cout << "Yes" << endl;
    return 0;
}