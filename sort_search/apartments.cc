#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = int64_t;

int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> A(n, 0);
  for (ll i = 0; i < n; i++) {
    cin >> A[i];
  }
  vector<ll> B(m, 0);
  for (ll i = 0; i < m; i++) {
    cin >> B[i];
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  ll ans = 0;
  ll bi = 0;
  for (ll i = 0; i < n; i++) {
    while (bi < m && B[bi] < A[i]-k) {
      bi++;
    }
    if (bi < m && A[i]-k <= B[bi] && B[bi] <= A[i] +k) {
      ans++;
      bi++;
    }
  }
  cout << ans << endl;
}
