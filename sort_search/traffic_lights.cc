#include <iostream>
#include <set>

using namespace std;
using ll = int64_t;

int main() {
  multiset<ll> L;
  ll x, n;
  cin >> x >> n;
  L.insert(x);
  set<ll> X;
  X.insert(0);
  X.insert(x);
  for (ll i = 0; i < n; i++) {
    ll p;
    cin >> p;
    auto it = X.upper_bound(p);
    ll upper = *it;
    it--;
    ll lower = *it;
    L.erase(L.find(upper-lower));
    L.insert(upper-p);
    L.insert(p-lower);
    X.insert(p);
    cout << (*L.rbegin()) << endl;
  }
}
