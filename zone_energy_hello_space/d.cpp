#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define INF 1001001001
#define LINF (1LL<<60)
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){ return a > b && (a = b, true); }
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){ return a < b && (a = b, true); }
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using ld = long double;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    deque<char> t;
    bool rev = false;
    for (char c: s) {
        if (c == 'R') {
            rev = !rev;
            continue;
        }

        if (rev) {
            if (!t.empty() && t.front() == c) {
                t.pop_front();
            }
            else t.push_front(c);
        }
        else {
            if (!t.empty() && t.back() == c) {
                t.pop_back();
            }
            else t.push_back(c);
        }
    }

    if (rev) {
        while (!t.empty()) {
            cout << t.back();
            t.pop_back();
        }
    }
    else {
        while (!t.empty()) {
            cout << t.front();
            t.pop_front();
        }
    }
    cout << endl;
    return 0;
}