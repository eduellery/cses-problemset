#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = int64_t;

int main() {
  ll n;
  cin >> n;
  vector<ll> A(n ,0);
  for (ll i = 0; i < n; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  ll target = A[n/2];
  ll cost = 0;
  for (ll i = 0; i < n; i++) {
    cost += abs(A[i] - target);
  }
  cout << cost << endl;
}
