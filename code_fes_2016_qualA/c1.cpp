#include <bits/stdc++.h>

using namespace std;

char s[1234567];

int main() {
  scanf("%s", s);
  int k;
  scanf("%d", &k);
  for (int i = 0; s[i]; i++) {
    if (s[i] != 'a') {
      int ops = 'z' - s[i] + 1;
      if (ops <= k) {
        k -= ops;
        s[i] = 'a';
      }
    }
  }
  int len = strlen(s);
  while (k--) {
    s[len - 1]++;
    if (s[len - 1] > 'z') {
      s[len - 1] = 'a';
    }
  }
  puts(s);
  return 0;
}
