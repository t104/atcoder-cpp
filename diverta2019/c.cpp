#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<string> a, b, ab, c;
    int count = 0;
    rep(i,n) {
        string s;
        cin >> s;
        int pos = s.find("AB");
        while (pos != string::npos) {
            count++;
            if (pos+2 < s.size()) pos = s.find("AB", pos+2);
            else break;
        }
        if(s.at(0) == 'B' && s.at(s.size()-1) == 'A') ab.push_back(s);
        else if (s.at(0) == 'B') b.push_back(s);
        else if (s.at(s.size() - 1) == 'A') a.push_back(s);
        else c.push_back(s);
    }
    int minab = min(a.size(), b.size());
    int maxab = max(a.size(), b.size());
    count += minab;
    if(0 < ab.size() && 0 == maxab) count += ab.size() - 1;
    else count += ab.size();
    cout << count << endl;
    return 0;
}