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

int main() {
  ll n;
  cin >> n;
  ll L = 1e6;
  vector<ll> F(L+1, 0);
  F[0] = 1;
  for (ll i = 1; i < (ll) F.size(); i++) {
    F[i] = MUL(i, F[i-1]);
  }
  // 1/n! * n = 1/(n-1)!
  vector<ll> FI(L+1, 0);
  FI[L] = INV(F[L]);
  for (ll i = L-1; i >=0; i--) {
    FI[i] = MUL(FI[i+1], i+1);
  }
  for (ll i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    ll ans = MUL(F[a], MUL(FI[b], FI[a-b]));
    cout << ans << endl;
  }
}

