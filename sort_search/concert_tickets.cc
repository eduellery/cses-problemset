#include <iostream>
#include <set>

using namespace std;
using ll = int64_t;

int main() {
  ll n, m;
  cin >> n >> m;
  multiset<ll, greater<ll>> A;
  for (ll i = 0; i < n; i++) {
    ll p;
    cin >> p;
    A.insert(p);
  }
  for (ll i = 0; i < m; i++) {
    ll p;
    cin >> p;
    auto it = A.lower_bound(p);
    if (it == A.end()) {
      cout << -1 << endl;
    } else {
      cout << (*it) << endl;
      A.erase(it);
    }
  }
}
