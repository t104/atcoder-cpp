#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

const map<string, int> mp = {
    {"Vacant", -1},
    {"Male", 0},
    {"Female", 1}
};

int read(int n) {
    string s;
    cout << n << endl;
    cin >> s;
    if (mp.at(s) == -1) exit(0);
    return mp.at(s);
}

int main() {
    int n;
    cin >> n;
    int li = 0;
    int ri = n-1;
    int l = read(li);
    int r = read(ri);

    while (true) {
        int mi = (li+ri)/2;
        int m = read(mi);
        if ((l == m) != ((mi-li)%2) == 0) {
            ri = mi;
            r = m;
        }
        else {
            li = mi;
            l = m;
        }
    }

    return 0;
}