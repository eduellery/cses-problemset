#include <iostream>
#include <set>

using namespace std;
using ll = int64_t;

int main() {
  multiset<ll> S;
  ll n;
  cin >> n;
  for (ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    auto it = S.upper_bound(x);
    if (it == S.end()) {
      S.insert(x);
    } else {
      S.erase(it);
      S.insert(x);
    }
  }
  cout << S.size() << endl;
}
