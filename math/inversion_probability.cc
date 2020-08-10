#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
using ll = int64_t;
using ld = double;

// We want to find the expected number of inversions.
// We can apply linearity of expectation:
// Define an indicator variable for each pair which is 1 if it is inverted and 0 otherwise.
// The number of inversions is the sum of these indicator variables.
// By linearity of expectation, the expected number of inversions is just the sum of the expectations of
// each of these indicator variables, which is just the sum of the probability that each pair is inverted.
//
// So what is the probability that the pair (i,j) is inverted? It depends on R_i and R_j.
// There are R_i * R_j possibilities for the values, each equally likely.
// How many are inversions?
//
// We could just enumerate all R_i * R_j pairs, but that gives O(100**4) running time, which might be too slow.
// Instead we can enumerate all R_i values for the first number.
// Then there are min(R_i-j, R_j) ways for the second number to be smaller (giving an inversion).
// So we can count the pairs in O(R_i) steps, giving O(100*3) running time, which is acceptable.

int main() {
  ll n;
  cin >> n;
  vector<ll> R(n, 0);
  for (ll i = 0; i < n; i++) {
    cin >> R[i];
  }
  ld ans = 0.0;
  for (ll i = 0; i < n; i++) {
    for (ll j = i+1; j < n; j++) {
      ll num_inversions = 0;
      for (ll a = 1; a <= R[i]; a++) {
        num_inversions += min(a-1, R[j]);
      }
      ld p = static_cast<ld>(num_inversions) / static_cast<ld>(R[i]*R[j]);
      ans += p;
    }
  }
  cout << fixed << setprecision(6) << ans << endl;
}
