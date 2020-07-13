#include <iostream>
using namespace std;
using ll = int64_t;

ll MOD = 1e9+7;
ll MUL(ll x, ll y, ll m) { return (x*y)%m; }
ll POW(ll b, ll e, ll m) {
  // Exponentiation by squaring
  if (e == 0) {
    return 1LL;
  } else if (e%2 == 0) {
    // Instead of b^e, (b^2)^(e/2)
    return POW(MUL(b, b, m), e/2, m);
  } else {
    return MUL(b, POW(b, e-1, m), m);
  }
}

int main() {
  ll n;
  cin >> n;
  for (ll i = 0; i < n; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    // For all a (1 <= a <= p-1), a^(p-1) (mod p) = 1 (mod p) for any prime p.
    // a^e (mod p) = a^(e%(p-1)) (mod p)
    ll d = POW(b, c, MOD-1);
    ll e = POW(a, d, MOD);
    cout << e << endl;
  }
}
