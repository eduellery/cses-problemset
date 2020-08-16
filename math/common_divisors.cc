#include <iostream>
#include <vector>

using namespace std;
using ll = int64_t;

int main() {
  ll n;
  cin >> n;
  vector<ll> A(n, 0);
  ll L = static_cast<ll>(1e6);
  vector<ll> COUNT(L+1, 0);
  for (ll i = 0; i < n; i++) {
    cin >> A[i];
    COUNT[A[i]]++;
  }

  for (ll d = L; d >= 1; d--) {
    ll count = 0;
    for (ll x = d; x <= L; x += d) {
      count += COUNT[x];
    }
    if (count >= 2) {
      cout << d << endl;
      return 0;
    }
  }
}
