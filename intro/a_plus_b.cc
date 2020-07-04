#include <iostream>
using namespace std;
using ll = int64_t; // go up to +- 9e18

/* You are given two integers A and B. Output their sum. */

int main() {
  ll a,b;
  // cin reads from stdin
  cin >> a >> b;
  ll ans = a+b;
  // cerr writes to stderr
  cerr << "DEBUG a=" << a << ", b=" << b << ", ans=" << ans << endl;
  // cout writes to stdout
  cout << ans << endl;
}
