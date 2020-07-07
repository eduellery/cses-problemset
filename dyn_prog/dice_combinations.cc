#include <iostream>
#include <vector>
using namespace std;
using ll = int64_t;

ll MOD = 1e9+7; // Prime
ll ADD(ll x, ll y) {
  return (x + y) % MOD;
}

// Memoization

vector<ll> DP;

ll dp(ll n) {
  if (n < 0) {
    return 0;
  }
  if (n == 0) {
    return 1;
  }
  if (DP[n] >= 0) {
    return DP[n];
  }
  ll ans = 0;
  for (ll roll = 1; roll <= 6; roll++) {
    ans = ADD(ans, dp(n - roll));
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
