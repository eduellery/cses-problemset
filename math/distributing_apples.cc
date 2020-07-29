#include <iostream>
#include <vector>

using namespace std;
using ll = int64_t;

// INV(x) is like 1/x. Key fact: MUL(x, INV(x)) = 1.
// Important fact: POW(x, MOD-1) = 1 for any x.
// POW(x, MOD-1) = MUL(x, POW(x, MOD-2)) = 1.
ll MOD = 1e9+7;
ll ADD(ll x, ll y) { return (x+y)%MOD; }
ll MUL(ll x, ll y) { return (x*y)%MOD; }
ll POW(ll b, ll e) { 
  if (e == 0) { return 1ll; }
  if (e%2 == 0) { return POW(MUL(b,b), e/2); }
  return MUL(b, POW(b, e-1));
}
ll INV(ll x) { return POW(x, MOD-2); }
ll DIV(ll x, ll y) { return MUL(x, INV(y)); }

// DADA
// C(n-1+m, m) = C(n-1+m, n-1).
// C(n, k) = n! / (k! * (n-k)!) = n! / ((n-k)! * k!).
// C(n, k) = C(n, n-k).

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> F(2e6, 0);
  F[0] = 1;
  for (ll i = 1; i < (ll) F.size(); i++) {
    F[i] = MUL(F[i-1], i);
  }
  ll ans = MUL(F[n-1+m], MUL(INV(F[m]), INV(F[n-1])));
  cout << ans << endl;
}

