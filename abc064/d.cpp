#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int a = 0;
    int l = 0;
    rep(i, n) {
        if (s.at(i) == '(') a++;
        if (s.at(i) == ')') a--;
        if (a < 0) {
            a++;
            l++;
        }
    }
    rep(i, l) s.insert(0, "(");
    rep(i, a) s.push_back(')');
    cout << s << endl;
    return 0;
}