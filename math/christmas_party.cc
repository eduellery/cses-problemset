#include <iostream>
#include <vector>

using namespace std;
using ll = int64_t;

ll MOD = static_cast<ll>(1e9+7);
ll ADD(ll x, ll y) { return (x+y)%MOD; }
ll MUL(ll x, ll y) { return (x*y)%MOD; }

// Let f(n) be the answer for n.
// Is there a recurrence for f? A way to break the problem for n down to into problems for smaller values? Yes.
//
// What happens to the first gift? The first child (1) can give to anyone else (n-1) choices. Say they give to child X.
// Child X can either give back to 1 or give to someone else.
// If X gives back to 1, the remaining children can give gifts in f(n-2) ways.
// Otherwise we know X gives to someone else. Then there are f(n-1) ways to finish giving the gifts.
//   There are n-1 gifts left to give, and for each gift there is one person left who can't get it.
//   X's gift can't be given to 1 (X doesn't count since he already got a gift).
//   Everyone else's gift can't be given to themselves.
//   So the number of ways to give out those n-1 gifts is just f(n-1).
//
// So f(n) = (n-1) * (f(n-1) + f(n-2)), since there are n-1 choices for X and each choice gives
// f(n-2) + f(n-1) ways to complete each gift-giving, depending on wheter X gives back to 1 or not.
//
// DP on this recurrence gives an O(n) solution.

int main() {
  ll n;
  cin >> n;
  vector<ll> F(n+1, 0);
  F[1] = 0;
  F[2] = 1;
  for (ll i = 3; i <= n; i++) {
    F[i] = MUL(i-1, ADD(F[i-1], F[i-2])); 
  }
  cout << F[n] << endl;
}
