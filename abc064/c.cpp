#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a.at(i);

    int free = 0;
    set<int> st;
    rep(i, n) {
        if(a.at(i)/400 >= 8) free++;
        else {
            st.insert(a.at(i)/400);
        }
    }

    if(st.size() == 0) cout << 1;
    else cout << st.size();

    cout << ' ' << st.size() + free << endl;

    return 0;
}