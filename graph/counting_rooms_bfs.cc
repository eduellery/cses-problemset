#include <iostream>
#include <vector>
#include <utility>
#include <deque>
#include <tuple>

using namespace std;
using ll = int64_t;
using pll = pair<ll,ll>;

// BFS starts traversal from the root node and visits nodes in a level by level manner 
// BFS uses Queue to find the shortest path and is better when target is closer to source
int main() {
  ll R,C;
  cin >> R >> C;
  vector<vector<int>> OK(R, vector<int>(C, false));
  
  for (ll r=0; r<R; r++) {
    string S;
    cin >> S;
    for (ll c=0; c<C; c++) {
      OK[r][c] = (S[c]=='.');
    }
  }
  
  ll ans = 0;
  vector<vector<int>> SEEN(R, vector<int>(C, false));
  
  // Coordinate System(row, column). (0,0) is top-left.
  // rows go down, columns go up.
  // 
  // up right down left (clockwise order)
  // up = -1 row
  // right = +1 column
  // down = +1 row
  // left = -1 column
  vector<ll> DR{-1,0,1,0};
  vector<ll> DC{0,1,0,-1};

  for (ll sr=0; sr<R; sr++) {
    for (ll sc=0; sc<C; sc++) {
      if (OK[sr][sc] && !SEEN[sr][sc]) {
        ans++;
	deque<pll> Q;
	Q.push_back(make_pair(sr,sc));
	while (!Q.empty()) {
	  ll r,c;
	  tie(r,c) = Q.front();
	  Q.pop_front();
	  if(!(0<=r && r<R && 0<=c && c<C)) { continue; }
	  if(!OK[r][c] || SEEN[r][c]) { continue; }
	  SEEN[r][c] = true;
          for (ll d=0; d<4; d++) {
	    Q.push_back(make_pair(r+DR[d], c+DC[d]));
	  }
        }
      }
    }
  }
  cout << ans << endl;
}
