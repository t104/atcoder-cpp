#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for(int i = 1; i < n; i++) {
        string x = s.substr(0, i);
        string y = s.substr(i, n-i);
        int count = 0;
        set<char> st;

        for(char c : x) {
            st.insert(c);
        }

        for(auto c : st) {
            if(y.find(c) != string::npos) count++;
        }
        ans = max(ans, count);
    }

    cout << ans << endl;

    return 0;
}