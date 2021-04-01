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

const int DAYSINYEAR = 366;
const vector<int> DAYSINMONTH = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int n;
    cin >> n;
    vector<bool> off(DAYSINYEAR, false);
    rep(i, DAYSINYEAR) {
        if (i%7 == 0) off[i] = true;
        if (i%7 == 6) off[i] = true;
    }
    rep(i,n) {
        string month_date;
        cin >> month_date;
        int sep = month_date.find("/");
        int month = stoi(month_date.substr(0,sep));
        int date = stoi(month_date.substr(sep+1, month_date.size() - sep+1))-1;
        rep(m, month) date += DAYSINMONTH[m-1];
        while (date < DAYSINYEAR-1 && off[date]) date++;
        off[date] = true;
    }
    int ans = 0, cnt = 0;
    rep(i,DAYSINYEAR) {
        if (off[i]) cnt++;
        else {
            chmax(ans,cnt);
            cnt = 0;
        }
    }
    chmax(ans, cnt);
    cout << ans << endl;
    return 0;
}