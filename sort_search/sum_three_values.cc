#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ll = int64_t;

int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> A(n, 0);
  multimap<ll, ll> M; // value -> idx
  for (ll i = 0; i < n; i++) {
    cin >> A[i];
    M.insert(make_pair(A[i], i+1));
  }
  // looking for i < j < k s.t. A[i] + A[j] + A[k] = x
  for (ll j = 0; j < n; j++) {
    M.erase(M.find(A[j]));
    for (ll i = 0; i < j; i++) {
      ll ak = x - A[i] - A[j];
      auto it = M.find(ak);
      if (it != M.end()) {
        cout << (i+1) << " " << (j+1) << " " << it->second << endl;
	return 0;
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
}
