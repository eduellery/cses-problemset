#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = int64_t;

int main() {
  ll n;
  cin >> n;
  vector<ll> A(n, 0);
  for(ll i=0; i<n; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  ll ans = 0;
  for(ll i=0; i<n; i++) {
    if(A[i] != A[i-1]) {
      ans++;
    }
  }
  cout << ans << endl;
}
