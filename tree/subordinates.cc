#include <iostream>
#include <vector>

using namespace std;
using ll = int64_t;

vector<vector<ll>> C;
vector<ll> SIZE;

void root(ll x) {
  ll size = 0;
  for (ll c : C[x]) {
    root(c);
    size += SIZE[c] + 1; // Number of subordinates of C plus C itself
  }
  SIZE[x] = size;
}

int main() {
  ll n;
  cin >> n;
  C = vector<vector<ll>>(n, vector<ll>{});
  SIZE = vector<ll>(n, 0);
  for (ll i = 1; i < n; i++) {
    ll p;
    cin >> p;
    p--;
    C[p].push_back(i);
  }
  root(0);
  for (ll i=0; i<n; i++) {
    cout << SIZE[i] << " ";
  }
  cout << endl;
}
