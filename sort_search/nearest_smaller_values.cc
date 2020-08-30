#include <iostream>
#include <vector>
#include <map>
#include <functional>

using namespace std;
using ll = int64_t;

int main() {
  ll n;
  cin >> n;
  vector<ll> A(n, 0);
  for (ll i = 0; i < n; i++) {
    cin >> A[i];
  }
  map<ll, ll, greater<ll>> M;
  for (ll i = 0; i < n; i++) {
    auto it = M.upper_bound(A[i]);
    if (it != M.end()) {
      cout << it->second << " ";
    } else {
      cout << 0 << " ";
    }
    while(!M.empty() && M.begin()->first >= A[i]) {
      M.erase(M.begin());
    }
    M.insert(make_pair(A[i], i+1));
  }
  cout << endl;
}
