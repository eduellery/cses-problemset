#include <iostream>
#include <vector>

using namespace std;
using ll = int64_t;

// Prefix sum array P
// P[i] = sum of A[0,i)
// P[0] = 0
// P[1] = A[0]
// P[2] = A[0]+A[1]
// P[3] = A[0]+A[1]+A[2] = P[2] + A[2]
// P[n] = A[0]+A[1]+...+A[n-1]
// A[a]+A[a+1]+...+A[b] = (A[0]+...+A[b]) - (A[0]+...+A[a-1]) = P[b+1] - P[a]

int main() {
  ll n,q;
  cin >> n >> q;
  vector<ll> A(n,0);
  for (ll i=0; i<n; i++) {
    cin >> A[i];
  }

  vector<ll> P(n+1, 0);
  P[0] = 0;
  for (ll i=1; i<=n ;i++) {
    P[i] = P[i-1] + A[i-1];
  }

  for (ll i=0; i<q; i++) {
    ll a,b;
    cin >> a >> b;
    a--; b--;
    ll ans = P[b+1]-P[a];
    cout << ans << endl;
  }
}
