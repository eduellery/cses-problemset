#include <iostream>
#include <algorithm>

using namespace std;
using ll = int64_t;

// A >= B >= C >= D >= E >= F
// K reads A. J reads B. Go through list in order.
// K will never get stuck! Why? K is always at least one book behind J,
// because K reads A and J hasn't. A is the biggest book,
// so always at least one book behind.
//
// J might stuck behind K! If A is very long relative to everything else.
// This gives us the 2*A case.
// If no one gets stuck, that gives us the "sum of all values case".
// Those are the only two cases, so the answer is the max of these.

int main() {
  ll n;
  cin >> n;
  ll sum = 0; 
  ll mx = 0;
  for (ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    sum += x;
    mx = max(mx, x);
  }
  ll ans = max(2*mx, sum);
  cout << ans << endl;
}
