#include <iostream>
#include <vector>

using namespace std;
using ll = int64_t;
using mat = vector<vector<ll>>;

ll INF = 2e18;

mat mat_mul(const mat& A, const mat& B) {
  mat C(A.size(), vector<ll>(B[0].size(), INF));
  for (ll i = 0; i < (ll) A.size(); i++) {
    for (ll j = 0; j < (ll) A[0].size(); j++) {
      for (ll k = 0; k < (ll) B[0].size(); k++) {
        C[i][k] = min(C[i][k], A[i][j]+B[j][k]);
      }
    }
  }
  return C;
}

mat mat_pow(mat A, ll e) {
  if (e == 1) { return A; } 
  else if (e % 2 == 0) { return mat_pow(mat_mul(A,A), e/2); }
  else { return mat_mul(A, mat_pow(A, e-1)); }
}

// Let P be the adjacency matrix. P[i][j] = min cost edge from i to j.
// If there is no edge from i to j, P[i][j] = INF.
// P[i][j] = min cost path from i to j with 1 edge.
// (P*P)[i][j] = min cost path from i to j with 2 edges? NO!
// (P*P)[i][j] = \sum_k P[i][k]*P[k][j].
// Actually, should be: \min_k P[i][k]+P[k][j].
// (P^a * P^b)[i][j] = \min_k P^a[i][k] + P^b[k][j].
// So why not just do matrix "multiplication" with that formula?

int main() {
  ll n, m, k;
  cin >> n >> m >> k;

  mat P(n, vector<ll>(n, INF)); 
  for (ll i = 0; i < m; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    P[a][b] = min(P[a][b], c);
  }

  mat Pk = mat_pow(P, k);
  cout << (Pk[0][n-1] >= INF ? -1 : Pk[0][n-1]) << endl;
}
