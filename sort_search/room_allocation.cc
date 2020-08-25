#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <algorithm>

using namespace std;
using ll = int64_t;
using pll = pair<ll, ll>;

int main() {
  ll n;
  cin >> n;
  vector<pll> E;
  ll next_room = 1;
  vector<ll> ANS(n, 0);
  deque<ll> EMPTY;
  for (ll i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    E.push_back(make_pair(a, i+1));
    E.push_back(make_pair(b+1, -(i+1)));
  }
  sort(E.begin(), E.end());
  for (ll i = 0; i < (ll) E.size(); i++) {
    ll id = E[i].second;
    if (id > 0) {
      if (EMPTY.size() > 0) {
        ll room = EMPTY.front();
	EMPTY.pop_front();
	ANS[id-1] = room;
      } else {
        ll room = next_room;
	next_room++;
	ANS[id-1] = room;
      }
    } else {
      ll room = ANS[(-id)-1];
      EMPTY.push_back(room);
    }
  }
  cout << (next_room-1) << endl;
  for (ll i = 0; i < n; i++) {
    cout << ANS[i] << " ";
  }
  cout << endl;
}
