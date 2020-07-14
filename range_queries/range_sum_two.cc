#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll LSB(ll n) { return n&(-n); }
struct fenwick {
  fenwick(ll n) : F(n+1, 0) {}
  void add (ll i, ll x) {
    while(i < F.size()) {
      F[i] += x;
      i += LSB(i);
    }
  }
  ll query(ll i) {
    ll sum = 0;
    while (i > 0) {
      sum += F[i];
      i -= LSB(i);
    }
    return sum;
  }
  vector<ll> F;
};

int main() {
  ll n, q;
  cin >> n >> q;
  fenwick F(n);
  for (ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    F.add(i+1, x);
  }
  for (ll i = 0; i < q; i++) {
    ll t, a, b;
    cin >> t >> a >> b;
    if (t == 1) {
      ll va = F.query(a) - F.query(a-1);
      F.add(a, b-va);
    } else {
      ll ans = F.query(b) - F.query(a-1);
      cout << ans << endl;
    }
  }
}
