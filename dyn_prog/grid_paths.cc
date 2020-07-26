#include <iostream>
#include <vector>

using namespace std;
using ll = int64_t;

ll MOD = 1e9+7;
ll ADD(ll x, ll y) { return (x+y)%MOD; };

int main() {
  ll n;
  cin >> n;
  // G[r][c] = true if we *can* walk on (r, c)
  vector<vector<char>> G(n, vector<char>(n, false));
  for (ll r = 0; r < n; r++) {
    string S;
    cin >> S;
    for (ll c = 0; c < n; c++) {
      G[r][c] = (S[c] == '.');
    }
  }

  // DP[r][c] = # of ways to go from (r, c) to (n-1, n-1) only going down and right
  // DP{r][c] = DP[r+1][c] (down) + DP[r][c+1] (right)
  vector<vector<ll>> DP(n, vector<ll>(n, 0));
  for (ll r = n-1; r >= 0; r--) {
    for (ll c = n-1; c >= 0; c--) {
      if (G[r][c]) {
        if (r == n-1 && c == n-1) {
	  DP[r][c] = 1;
	} else {
	  DP[r][c] = ADD((r+1 < n ? DP[r+1][c] : 0ll), (c+1 < n ? DP[r][c+1] : 0ll));
	}
      } else {
        DP[r][c] = 0;
      }
    }
  }

  cout << DP[0][0] << endl;
}
