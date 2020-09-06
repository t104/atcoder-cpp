#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

bool unique(vector<char> s) {
    char c = s.at(0);
    for (char x : s) {
        if (x != c) return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    set<char> st;
    rep(i, s.size()) {
        st.insert(s.at(i));
    }
    int ans = 1e9;
    for (auto c : st) {
        int count = 0;
        vector<char> sv(s.size());
        rep(i,s.size()) sv.at(i) = s.at(i);
        while(!unique(sv)) {
            vector<char> next;
            rep(i, sv.size()-1) {
                if (sv.at(i) == c) next.push_back(sv.at(i));
                else next.push_back(sv.at(i+1));
            }
            sv = next;
            count++;
        }
        ans = min(ans, count);
    }
    cout << ans << endl;
    return 0;
}