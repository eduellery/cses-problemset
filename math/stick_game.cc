#include <iostream>
#include <vector>

using namespace std;
using ll = int64_t;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> P(k, 0);
  for (ll i = 0; i < k; i++) {
    cin >> P[i];
  }
  vector<int> W(n+1, false);
  W[0] = false;
  for (ll i = 1; i <= n; i++) {
    for (ll j = 0; j < k; j++) {
      if (i-P[j] >= 0 && !W[i-P[j]]) {
        W[i] = true;
      }
    }
  }
  for (ll i = 1; i <= n; i++) {
    cout << (W[i] ? 'W' : 'L');
  }
  cout << endl;
}
