#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = int64_t;

int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> A(n, 0);
  for (ll i = 0; i < n; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  ll ei = n - 1;
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    if (i > ei) { break; }
    while (ei > i && A[i]+A[ei] > x) {
      ei--;
      ans++;
    }
    ans++;
    ei--;
  }
  cout << ans << endl;
}
