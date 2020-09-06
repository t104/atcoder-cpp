#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    set<char> st;
    for(char c : s) {
        st.insert(c);
    }
    if(s.size() == st.size()) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}