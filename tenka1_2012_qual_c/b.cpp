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

map<char, int> mp = {
    {'A', 1},
    {'J', 11},
    {'Q', 12},
    {'K', 13}
};

map<char, int> mark_mp {
    {'S', 0},
    {'H', 1},
    {'D', 2},
    {'C', 3}
};

struct card {
    int mark;
    int idx;
    string to_str;
    bool needed = false;

    static card read(int &i, string &s) {
        card c;
        c.mark = mark_mp.at(s[i]);
        c.to_str.push_back(s[i]);
        if (mp.count(s[i+1])) {
            c.idx = mp.at(s[i+1]);
            c.to_str.push_back(s[i+1]);
            i = i + 2;
        } else if (s[i+1] == '1') {
            c.idx = 10;
            c.to_str.push_back(s[i+1]);
            c.to_str.push_back(s[i+2]);
            i = i + 3;
        } else {
            c.idx = s[i+1] - '0';
            c.to_str.push_back(s[i+1]);
            i = i + 2;
        }
        return c;
    }
};


int main() {
    string s;
    cin >> s;
    vector<card> cards;
    vector<int> flgs(4);
    int keep_mark = -1;
    for (int i = 0; i < (int) s.size();) {
        card c = card::read(i, s);
        int idx = (c.idx + 3) % 13;
        if (idx < 5 && (~flgs[c.mark]>>idx)&1) {
            c.needed = true;
            flgs[c.mark] |= (1<<idx);
        }
        if (flgs[c.mark] == ((1<<5) - 1)) {
            keep_mark = c.mark;
            break;
        }
        cards.push_back(c);
    }
    stringstream ss;
    for (auto &c: cards) {
        if (c.needed && c.mark == keep_mark) continue;
        ss << c.to_str;
    }
    if (ss.str().size() == 0) cout << 0 << endl;
    else cout << ss.str() << endl;
    return 0;
}

