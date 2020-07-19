#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = int64_t;
using pll = pair<ll, ll>;

int main() {
  ll n;
  cin >> n;
  vector<pll> E;
  for (ll i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    E.push_back({a,1});
    E.push_back({b,-1});
  }
  sort(E.begin(), E.end());
  ll ans = 0;
  ll cur = 0;
  for (ll i = 0; i < (ll) E.size(); i++) {
    cur += E[i].second;
    ans = max(ans, cur);
  }
  cout << ans << endl;
}
