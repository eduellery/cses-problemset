#include <iostream>
#include <vector>

using namespace std;
using ll = int64_t;

bool ok(ll x, ll t, const vector<ll>& A) {
  ll ans = 0;
  for (ll i = 0; i < (ll) A.size(); i++) {
    ans += x / A[i];
    if (ans >= t) {
      return true;
    }
  }
  return false;
}

int main() {
  ll n, t;
  cin >> n >> t;
  vector<ll> A(n, 0);
  for (ll i = 0; i < n; i++) {
    cin >> A[i];
  }

  ll lo = 0;
  ll hi = static_cast<ll>(1e18);
  // Done when lo == hi
  // Need to make sure it terminates when lo = 0 and hi = 1
  while (lo < hi) {
    ll mid = (lo+hi) / 2;
    if (ok(mid, t, A)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  cout << lo << endl;
}
