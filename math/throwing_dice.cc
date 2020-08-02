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

// D_n = D_{n-1} + D_{n-2} + ... + D_{n-6}
// V_n = [D_n D_{n-1} ... D_{n-5}]
// M * V_n = V_{n-1} = [D_{n+1} D_n ... D_{n-4}]

int main() {
  ll n;
  cin >> n;

  vector<ll> D(10, 0);
  D[0] = 1ll;
  for (ll i = 1; i < (ll) D.size(); i++) {
    for (ll j = 1; j <= 6; j++) {
      if (i-j >= 0) { D[i] = ADD(D[i], D[i-j]); }
    }
  }

  if (n < (ll) D.size()) { 
    cout << D[n] << endl;
  } else {
    mat V0{{1}, {0}, {0}, {0}, {0}, {0}};
    mat M{{1,1,1,1,1,1},
          {1,0,0,0,0,0},
	  {0,1,0,0,0,0},
	  {0,0,1,0,0,0},
	  {0,0,0,1,0,0},
	  {0,0,0,0,1,0}};
    mat Mn = mat_pow(M, n);
    mat Vn = mat_mul(Mn, V0);
    cout << Vn[0][0] << endl;
  }
}
