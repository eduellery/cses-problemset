#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = int64_t;

// \sum_{tasks} d - f = \sum_{tasks} d - \sum_{tasks} f
// f0 = d0
// f1 = d0+d1
// f2 = d0+d1+d2
// f3 = d0+d1+d2+d3
// sum of f = n*d0 + (n-1)*d1 + ... + d_{n-1}

int main() {
  ll n;
  cin >> n;
  vector<ll> A(n, 0);
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    ll x;
    cin >> A[i] >> x;
    ans += x;
  }
  sort(A.begin(), A.end());
  ll f = 0;
  for (ll i = 0; i < n; i++) {
    f += A[i];
    ans -= f;
  }
  cout << ans << endl;
}
