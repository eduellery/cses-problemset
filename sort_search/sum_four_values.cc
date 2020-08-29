#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;
using ll = int64_t;
using pll = pair<ll,ll>;

int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> A(n, 0);
  multimap<ll,pll> M;
  for (ll i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (ll i = 0; i < n; i++) {
    for (ll j = i+1; j < n; j++) {
      M.insert(make_pair(A[i]+A[j], make_pair(i+1, j+1)));
    }
  }
  // looking for i < j < k < l s.t. A[i] + A[j] + A[k] + A[l] = x
  for (ll j = 0; j < n; j++) {
    for (ll k = j+1; k < n; k++) {
      M.erase(M.find(A[j]+A[k]));
    }
    for (ll i = 0; i < j; i++) {
      ll remaining = x - A[i] - A[j];
      auto it = M.find(remaining);
      if (it != M.end()) {
	auto [k,l] = it->second;
        cout << (i+1) << " " << (j+1) << " " << k << " " << l << endl;
	return 0;
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
}
