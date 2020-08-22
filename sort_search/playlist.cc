#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = int64_t;

int main() {
  ll n;
  cin >> n;
  vector<ll> A(n ,0);
  for (ll i = 0; i < n; i++) {
    cin >> A[i];
  }
  set<ll> SONGS;
  ll start = 0;
  ll ans = 0;
  // length of [a,b] is b-a+1
  for (ll i = 0; i < n; i++) {
    while(SONGS.count(A[i])) {
      SONGS.erase(A[start]);
      start++;
    }
    SONGS.insert(A[i]);
    ans = max(ans, i-start+1);
  }
  cout << ans << endl;
}
