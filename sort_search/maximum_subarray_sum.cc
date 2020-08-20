#include <iostream>
#include <vector>

using namespace std;
using ll = int64_t;

int main() {
  ll n;
  cin >> n;
  vector<ll> A(n, 0);
  for (ll i = 0; i < n; i++) {
    cin >> A[i];
  }
  ll best_sum = A[0];
  ll current_sum = 0;
  for (ll i = 0; i < n; i++) {
    current_sum += A[i];
    best_sum = max(best_sum, current_sum);
    if (current_sum < 0) {
      current_sum = 0;
    }
  }
  cout << best_sum << endl;
}
