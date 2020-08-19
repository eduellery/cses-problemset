#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
using ll = int64_t;
using pll = pair<ll, ll>;

int main() {
  ll n, x;
  cin >> n >> x;
  vector<pll> A(n, make_pair(0,0));
  for (ll i = 0; i < n; i++) {
    ll v;
    cin >> v;
    A[i] = make_pair(v, i+1);
  }
  sort(A.begin(), A.end());
  ll end = n-1;
  for (ll i = 0; i < n; i++) {
    while (end - 1 >= 0 && A[i].first + A[end].first > x) {
      end--;
    }
    if (A[i].second != A[end].second && A[i].first + A[end].first == x) {
      cout << A[i].second << " " << A[end].second << endl;
      return 0;
    }
  }
  cout << "IMPOSSIBLE" << endl;
}
