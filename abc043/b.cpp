#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    deque<char> dq;
    for (char c : s) {
        if (c == 'B' && !dq.empty()) dq.pop_back();
        if (c != 'B') dq.push_back(c);
    }
    while (!dq.empty()) {
        cout << dq.front();
        dq.pop_front();
    }
    cout << endl;
    return 0;
}