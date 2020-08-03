#include <iostream>
#include <vector>

using namespace std;
using ll = int64_t;
using mat = vector<vector<ll>>;

// https://en.wikipedia.org/wiki/Barrett_reduction
//****************************************************************************//
using ull = unsigned long long;
using L = __uint128_t;
struct FastMod {
  ll b, m;
  FastMod(ll b_) : b(b_), m(ll((L(1) << 64) / b)) {}
  ll reduce(ll a) {
    ll q = (ll)((L(m) * a) >> 64);
    ll r = a - q * b; // can be proven that 0 <= r < 2*b
    return r >= b ? r - b : r;
  }
};

ll MOD = 1e9+7;
FastMod F(MOD);

ll ADD(ll x, ll y) { return F.reduce(x+y); }
ll MUL(ll x, ll y) { return F.reduce(x*y); }
//****************************************************************************//

// AxB x BxC = AxC 
mat mat_mul(const mat& A, const mat& B) {
  mat C(A.size(), vector<ll>(B[0].size(), 0));
  for (ll i = 0; i < (ll) A.size(); i++) {
    for (ll j = 0; j < (ll) A[0].size(); j++) {
      for (ll k = 0; k < (ll) B[0].size(); k++) {
        C[i][k] = ADD(C[i][k], MUL(A[i][j], B[j][k]));
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

// Let P[i][j] be the number of edges from i to j.
// P[i][j] is the number of paths from i to j that uses 1 edge!
// (P*P)[i][j] is the number of paths from i to j that uses 2 edges!
// P^n[i][j] is the number of paths from i to j that uses n edges!
// Why? (P*P)[i][j] = \sum_k P[i]P[k]*P[k][j]
// (P^a * P^b)[i][j] = \sum_k P^a[i][k]*P^b[k][j]

int main() {
  ll n, m, k;
  cin >> n >> m >> k;

  mat P(n, vector<ll>(n, 0));
  for (ll i = 0; i < m; i++) {
    ll a,b;
    cin >> a >> b;
    a--; b--;
    P[a][b]++;
  }
  mat Pk = mat_pow(P, k);
  cout << Pk[0][n-1] << endl;
}
