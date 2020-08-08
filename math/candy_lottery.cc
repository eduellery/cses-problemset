#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = int64_t;
using ld = double;

// Let X be a positive integer valued random variable.
// E[X] = 1*P(1)  + 2*P(2)  + 3*P(3)  + ...
//      = P(1)    + P(2)    + P(3)    + ... = P(X>=1)
//                + P(2)    + P(3)    + ... = P(X>=2)
//                          + P(3)    + ... = P(X>=3)
//                                    + ...
//
//      = P(X>=1) + P(X>=2) + P(X>=3) + ...
//
// We want to find E[max number of candies]
// P(max number of candies >= A) = 1 - P(max <A)
//                               = 1 - P(all children get <A candies)
//
// P(child gets <A candies) = (A-1)/K
// P(all N children get <A candies) = ((A-1)/K)^N
//
// P(max >= A) = 1 - ((A-1)/K)^N
// ans = sum_{A-1}^K ((A-1)/K)^N

int main() {
  ll n, k;
  cin >> n >> k;
  ld ans = 0.0;
  for (ll a = 1; a <= k; a++) {
    ld p = (a-1.0)/static_cast<ld>(k);
    ans += 1.0 - pow(p, n);
  }
  cout << fixed << setprecision(6) << ans << endl;
}
