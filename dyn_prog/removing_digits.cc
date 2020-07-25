#include <iostream>
#include <vector>

using namespace std;
using ll = int64_t;

// DP[n] = number of steps to get to 0
vector<ll> DP;

ll dp(ll n) {
  if (n == 0) { return 0ll; }
  if (DP[n] >=  0) { return DP[n]; }
  vector<char> OK(10, false);
  ll tmp = n;
  while (tmp > 0) {
    OK[tmp%10] = true;
    tmp /= 10;
  }
  ll ans = n;
  for (ll d = 1; d <= 9; d++) {
    if (OK[d]) {
      ans = min (ans, 1+dp(n-d));
    }
  }
  DP[n] = ans;
  return ans;
}

int main() {
  ll n;
  cin >> n;
  DP = vector<ll>(n+1, -1);
  ll ans = dp(n);
  cout << ans << endl;
}
