#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    const int inf = 1 << 30;
    int n = s.size();
    vector<int> dp_1(n+1, -inf), dp_2(n+1, -inf);
    dp_1.at(0) = 0, dp_2.at(0) = 0;
    for (int i = 1; i < n+1; ++i) {
        // 2 文字のつぎ 1 文字を選ぶ。文字数が違うから必ず違う文字になる。
        dp_1.at(i) = dp_2.at(i-1) + 1;
        // 1 文字選んで次も 1 文字選ぶ。文字が違う時しか選べない。
        if (2 <= i && s.at(i-2) != s.at(i-1)) {
            dp_1.at(i) = max(dp_1.at(i), dp_1.at(i-1) + 1);
        }
        if ( 2 <= i) {
            // 1 文字のつぎ 2 文字選ぶ。文字数が違うから必ず違う文字になる。
            dp_2.at(i) = dp_1.at(i-2) + 1;
            // 2 文字選んで次も 2 文字選ぶ。文字が違う時しか選べない。
            if (4 <= i && (s.at(i-4) != s.at(i-2) || s.at(i-3) != s.at(i-1))) {
                dp_2.at(i) = max(dp_2.at(i), dp_2.at(i-2) + 1);
            }
        }
    }
    cout << max(dp_1.at(n), dp_2.at(n)) << endl;
    return 0;
}