#include <iostream>
using namespace std;
using ll = int64_t;

ll MOD = 1e9+7;
ll MUL(ll x, ll y) { return (x*y)%MOD; }
ll POW(ll b, ll e) {
  // Exponentiation by squaring
  if (e == 0) {
    return 1LL;
  } else if (e%2 == 0) {
    // Instead of b^e, (b^2)^(e/2)
    return POW(MUL(b, b), e/2);
  } else {
    return MUL(b, POW(b, e-1));
  }
}

int main() {
  ll n;
  cin >> n;
  for (ll i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    ll ans = POW(a, b);
    cout << ans << endl;
  }
}
