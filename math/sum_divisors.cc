#include <iostream>
#include <cmath>

using namespace std;
using ll = int64_t;

ll MOD = static_cast<ll>(1e9+7);
ll ADD(ll x, ll y) { return (x+y)%MOD; }
ll SUB(ll x, ll y) { return ADD(x, MOD-y); }
ll MUL(ll x, ll y) { x  %= MOD; y %= MOD; return (x*y)%MOD; }

ll S(ll n) {
  if (n%2 == 0) { return MUL(n/2, n+1); }
  else { return MUL(n, (n+1)/2); }
}

int main() {
  ll n;
  cin >> n;
  ll R = static_cast<ll>(sqrt(n));
  ll ans = 0;
  for (ll d = 1; d <= R; d++) {
    ans = ADD(ans, MUL(d, n/d)); 
  }
  for (ll A = 1; A <= R; A++) {
    ll LO = max(R+1, n/(A+1)+1);
    ll HI = n/A;
    if (LO <= HI) {
      ans = ADD(ans, MUL(A, SUB(S(HI), S(LO-1))));
    }
  }
  cout << ans << endl;
}
