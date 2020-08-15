#include <iostream>
#include <vector>

using namespace std;
using ll = int64_t;

// L + L/2 + L/3 + ... + L/L
// L * (1 + 1/2 + 1/3 + ... + 1/L)
// L * harmonic_series(L)
// ~ L * lg(L)
// harmonic_series(L) ~ ln(L)
// 1/2 + 1/3 + ... ~ log(log(n))

int main() {
  ll L = static_cast<ll>(1e6);
  vector<ll> F(L+1, 0);
  for (ll d = 1; d <= L; d++) {
    for (ll x = d; x <= L; x += d) {
      F[x]++;
    }
  }

  ll n;
  cin >> n;
  for (ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    cout << F[x] << endl;
  }
}
