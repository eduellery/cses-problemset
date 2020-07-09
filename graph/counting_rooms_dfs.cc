#include <iostream>
#include <vector>
#include <utility>
#include <deque>
#include <tuple>

using namespace std;
using ll = int64_t;
using pll = pair<ll,ll>;

// DFS starts the traversal from the root node and visits nodes as far as possible from the root node 
// DFS uses Stack to find the shortest path 

// Coordinate System(row, column). (0,0) is top-left.
// rows go down, columns go up.
// 
// up right down left (clockwise order)
// up = -1 row
// right = +1 column
// down = +1 row
// left = -1 column
ll R,C;
vector<ll> DR{-1,0,1,0};
vector<ll> DC{0,1,0,-1};
vector<vector<int>> OK;
vector<vector<int>> SEEN;

void dfs(ll r, ll c) {
  if(!(0<=r && r<R && 0<=c && c<C)) { return; }
  if(!OK[r][c] || SEEN[r][c]) { return; }
  SEEN[r][c] = true;
  for (ll d=0; d<4; d++) {
    dfs(r+DR[d], c+DC[d]); 
  }
}

int main() {
  cin >> R >> C;
  OK = vector<vector<int>>(R, vector<int>(C, false));
  
  for (ll r=0; r<R; r++) {
    string S;
    cin >> S;
    for (ll c=0; c<C; c++) {
      OK[r][c] = (S[c]=='.');
    }
  }
  
  ll ans = 0;
  SEEN = vector<vector<int>>(R, vector<int>(C, false));
  

  for (ll sr=0; sr<R; sr++) {
    for (ll sc=0; sc<C; sc++) {
      if (OK[sr][sc] && !SEEN[sr][sc]) {
        ans++;
	dfs(sr, sc);
      }
    }
  }
  cout << ans << endl;
}
