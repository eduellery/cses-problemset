#include <iostream>

using namespace std;
using ll = int64_t;

// Check Nim Game (I and II) readme files to understand the concept
int main() {
  ll T;
  cin >> T;
  for (ll cas = 1; cas <= T; cas++) {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
      ll x;
      cin >> x;
      if (i % 2 == 1) {
        ans ^= x;
      }
    }
    cout << (ans == 0 ? "second" : "first") << endl;
  }
}
