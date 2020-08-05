#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
using ll = int64_t;
using ld = double;

// P[i][k] = probability of getting K with I dice.
// P[0][0] = 1.0.
// P[0][x] = 0.0.
// P[i][k] = \sum_{d-1}^6 P[i-1][k-d] / 6.0

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  vector<vector<ld>> P(n+1, vector<ld>(6*n+1, 0.0));
  
  P[0][0] = 1.0;
  for (ll i = 1; i <= n; i++) {
    for (ll k = 1; k <= 6*n; k++) {
      for (ll d = 1; d <= 6; d++) {
        if (k-d >= 0) {
	  P[i][k] += P[i-1][k-d]/6.0;
	}
      }
    }
  }

  ld ans = 0.0;
  for (ll i = a; i <= b; i++) {
    ans += P[n][i];
  }
  cout << fixed << setprecision(6) << ans << endl;
}
