#include <iostream>
using namespace std;
using ll = int64_t;

int main() {
  ll n;
  cin >> n;
  while(n!=1) {
    cout << n << " ";
    if (n==1) { break; }
    if (n%2==0) {
      n /= 2;
    } else {
      n = n*3+1;
    }
  }
  cout << 1 << endl;
}
