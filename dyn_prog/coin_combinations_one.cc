#include <iostream>
#include <vector>

using namespace std;
using ll = int64_t;

ll MOD = 1e9+7;
ll ADD(ll x, ll y) { return (x+y)%MOD; }

int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> A(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  // DP[n] = # of ways to make n using coins
  // DP[n] = sum{a in A} dp(n-a)
  vector<ll> DP(x+1, -1);
  DP[0] = 1ll;
  for (ll y = 1; y <= x; y++) {
    ll dy = 0;
    for (ll a : A) {
      if (y-a >= 0) {
        dy += DP[y-a];
      }
    }
    DP[y] = dy%MOD;
  }
  cout << DP[x] << endl;
}
