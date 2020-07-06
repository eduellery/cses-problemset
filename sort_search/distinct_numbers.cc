#include <iostream>
#include <set>
using namespace std;
using ll = int64_t;

int main() {
  ll n;
  cin >> n;
  set<ll> A;
  for(ll i=0; i<n; i++) {
    ll x;
    cin >> x;
    A.insert(x);
  }
  cout << A.size() << endl;
}
