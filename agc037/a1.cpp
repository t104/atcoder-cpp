#include <bits/stdc++.h>
#define loop(n) for (int ngtkana_is_geneous = 0; ngtkana_is_geneous < n; ngtkana_is_geneous++)
#define rep(i, begin, end) for(int i = begin; i < end; i++)

#define LOCAL
using std::to_string;
auto to_string(std::string s) -> std::string {
  return '"' + s + '"';
}
auto to_string(char c) -> std::string {
  return "'" + std::string{c} + "'";
}
auto to_string(const char* s) -> std::string {
  return to_string((std::string) s);
}
auto to_string(bool b) -> std::string {
  return (b ? "true" : "false");
}
template <typename T, typename U>
auto to_string(std::pair<T, U> p) -> std::string {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <size_t N>
auto to_string(std::bitset<N> bs) -> std::string {
  std::string res{};
  for (size_t i = 0; i < N; i++)
    res.insert(res.begin(), bs.test(i) ? '1' : '0');
  return res;
}
template <typename T>
auto to_string(T v) -> std::string {
  bool flg = false;
  std::string res = "{";
  for (auto const&x : v) {
    if (flg) res += ", ";
    else flg = true;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { std::cerr << std::endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  std::cerr << " " << to_string(H);
  debug_out(T...);
}
#ifdef LOCAL
#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template<typename T, typename U>
inline auto cmn (T& a, U b) {if (a > b) {a = b; return true;} return false;}
template<typename T, typename U>
inline auto cmx (T& a, U b) {if (a < b) {a = b; return true;} return false;}

int main()
{
  std::cin.tie(0); std::cin.sync_with_stdio(false);
  std::string s; std::cin >> s;
  int n = s.length();
  constexpr int inf = 1 << 30;
  auto dp = std::vector<int>(n + 1, -inf);
  auto ep = std::vector<int>(n + 1, -inf);
  dp.at(0) = 0;
  ep.at(0) = 0;
  rep(i, 1, n + 1)
  {
    dp.at(i) = ep.at(i - 1) + 1;
    if (i >= 2 && s.at(i - 2) != s.at(i - 1))
    {
      cmx(dp.at(i), dp.at(i - 1) + 1);
    }
    if (i >= 2)
    {
      ep.at(i) = dp.at(i - 2) + 1;
      if (i >= 4 && (s.at(i - 4) != s.at(i - 2) || s.at(i - 3) != s.at(i - 1)))
      {
        cmx(ep.at(i), ep.at(i - 2) + 1);
      }
    }
  }
  std::cout << std::max(dp.at(n), ep.at(n)) << std::endl;
  return 0;
}
