#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

bool match(string s, string t) {
    rep(i, s.size()) {
        if(s.at(i) != '?' & s.at(i) != t.at(i)) {
            return false;
        }
    }
    return true;
}

int main() {
    string s, t;
    cin >> s >> t;
    stack<string> st;
    rep(i, s.size() - t.size() + 1) {
        string ans = s;
        string subs = ans.substr(i, t.size());
        if(match(subs, t)) {
            ans.replace(i, t.size(), t);
            st.push(ans);
        }
    }
    if(st.empty()) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    string ans = st.top();
    for(int pos = ans.find("?"); pos != string::npos; pos = ans.find("?")) {
        ans.replace(pos, 1, "a");
    }
    cout << ans << endl;
    
    return 0;
}