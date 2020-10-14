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
    cin >> n;
    set<int> st;
    rep(i,n) {
        int a;
        cin >> a;
        st.insert(a);
    }
    int ans = st.size();
    if (ans%2 == 0) ans--;
    cout << ans << endl;
    return 0;
}