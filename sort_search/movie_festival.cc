#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = int64_t;
using pll = pair<ll, ll>;
int main() {
  ll n = 0;
  cin >> n;
  vector<pll> A(n, {0, 0});
  for (ll i = 0; i < n; i++) {
    cin >> A[i].second >> A[i].first;
  }
  sort(A.begin(), A.end());
  ll ans = 1;
  ll t = A[0].first;
  for (ll i = 0; i < n; i++) {
    if(A[i].second >= t) {
      ans++;
      t = A[i].first;
    }
  }
  cout << ans << endl;
}
