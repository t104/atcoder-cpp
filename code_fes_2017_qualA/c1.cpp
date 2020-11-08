/**
 *    author:  tourist
 *    created: 23.09.2017 15:03:08       
**/
#include <bits/stdc++.h>

using namespace std;

void err() {
  puts("No");
  exit(0);
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<int> cnt(26, 0);
  for (int i = 0; i < h; i++) {
    string s;
    cin >> s;
    for (char c : s) {
      cnt[c - 'a']++;
    }
  }
  if ((h * w) % 2 == 1) {
    for (int i = 0; i < 26; i++) {
      if (cnt[i] % 2 == 1) {
        cnt[i]--;
        break;
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    if (cnt[i] % 2 == 1) {
      err();
    }
  }
  int k2 = 0;
  if (h % 2 == 1) {
    k2 += w / 2;
  }
  if (w % 2 == 1) {
    k2 += h / 2;
  }
  int have2 = 0;
  for (int i = 0; i < 26; i++) {
    have2 += (cnt[i] % 4 == 2);
  }
  if (have2 > k2) {
    err();
  }
  puts("Yes");
  return 0;
}
