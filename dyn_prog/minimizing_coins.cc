#include <iostream>
#include <vector>

using namespace std;
using ll = int64_t;

ll INF = 1e12;

// dp(N) is the minimum number of coins to make N
// dp(0) = 0
// dp(N) = 1 + min(i) DP(N-A[i])

vector<ll> DP;

ll dp(ll n, const vector<ll>& A) {
  if (n < 0) { return INF; }
  if (n == 0) { return 0LL; }
  if (DP[n] >= 0) { return DP[n]; }
  ll ans = INF;
  for (ll i = 0; i < (ll) A.size(); i++) {
    ans = min(ans, 1 + dp(n - A[i], A));
  }
  DP[n] = ans;
  return ans;
}

int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> A(n, 0);
  for (ll i = 0; i < n; i++) {
    cin >> A[i];
  }
  DP = vector<ll>(x + 1, -1);
  ll ans = dp(x, A);
  cout << (ans == INF ? -1 : ans) << endl;
}
