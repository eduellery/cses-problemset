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
  string S;
  cin >> S;
  ll empty = S.size();
  vector<ll> C(26, 0);
  for (ll i = 0; i < (ll) S.size(); i++) {
    C[S[i]-'a']++;
  }
  vector<ll> F(1e6+1, 0);
  F[0] = 1;
  for (ll i = 1; i < (ll) F.size(); i++) {
    F[i] = MUL(i, F[i-1]);
  }
  // 1/n! * n = 1/(n-1)!
  vector<ll> FI(F.size(), 0);
  FI[FI.size()-1] = INV(F[F.size()-1]);
  for (ll i = (ll) FI.size()-2; i >=0; i--) {
    FI[i] = MUL(FI[i+1], i+1);
  }
  // B(n,k) = binomial coefficient n choose k = F[n] * FI[k] * FI[n-k].
  // B(n, C[a]) * B(n-C[a], C[b]) * B(n-C[a]-C[b], C[c]).

  ll ans = 1;
  for (ll i = 0; i < 26; i++) {
    ll bni = MUL(F[empty], MUL(FI[C[i]], FI[empty-C[i]]));
    empty -= C[i];
    ans = MUL(ans, bni);
  }
  cout << ans << endl;
}

