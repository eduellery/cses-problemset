#include <iostream>
#include <vector>
using namespace std;
using ll = int64_t;

int main() {
  ll n;
  cin >> n;
  vector<ll> A;
  while(n!=1) {
    A.push_back(n);
    if (n==1) { break; }
    if (n%2==0) {
      n /= 2;
    } else {
      n = n*3+1;
    }
  }
  A.push_back(1);
  for (ll x : A) {
    cout << x << " "; // CSES allows trailing spaces
  }
  cout << endl;
}
