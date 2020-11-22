#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int fox_count = 0;
    stack<char> st;
    rep(i,n) {
        bool fox = false;
        if (s[i] == 'x' && !st.empty()) {
            char o = st.top();
            if (o == 'o') {
                st.pop();
                char f = st.top();
                if (f == 'f') {
                    st.pop();
                    fox = true;
                }
                else {
                    st.push(o);
                }
            }
        }
        if (!fox) {
            st.push(s[i]);
        }
    }

    cout << st.size() << endl;
    return 0;
}