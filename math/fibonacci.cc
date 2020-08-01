#include <iostream>
#include <vector>

using namespace std;
using ll = int64_t;
using mat = vector<vector<ll>>;

ll MOD = 1e9+7;
ll ADD(ll x, ll y) { return (x+y)%MOD; }
ll MUL(ll x, ll y) { return (x*y)%MOD; }

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

// V_n = [F_n F_{n-1}]
// matrix M
//
// M * V_n = V_{n+1} = [F_{n+1} F_n]
// M = [[a b][c d]]
// M * V_n = [a * F_n + b * F_{n-1}, c * F_n + d * F_{n-1}]
// M = [[1 1][1 0]]
// (M^4) * V_n = V_{n+4}
// How to compute F_n? M^i{n-1} V_1 = V_n
// Can compute M^n in log time with exponentiation by squaring

int main() {
  ll n;
  cin >> n;
  if (n == 0) { cout << 0 << endl; }
  else if (n == 1) { cout << 1 << endl; }
  else {
    mat V1{{1}, {0}};
    mat M{{1, 1}, {1, 0}};
    mat Mn1 = mat_pow(M, n-1);
    mat Vn = mat_mul(Mn1, V1);
    cout << Vn[0][0] << endl;
  }
}
