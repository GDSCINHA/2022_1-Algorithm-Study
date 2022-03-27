#include <iostream>

using namespace std;

//          ⬇️  ⬅️  ⬆️  ➡️;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int dir = 0;

int map[101][101];

int main() {
  int N;
  string cmd;
  
  cin >> N;
  cin >> cmd;

  int x = 50, y = 50;
  int l = 50, r = 50;
  int b = 50, t = 50;
  
  for (int i = 0; i < N; i++) {
    if (cmd[i] == 'R') {
      map[x][y] = 1;
      dir = (dir + 1) % 4;
    }
    else if (cmd[i] == 'L') {
      map[x][y] = 1;
      dir = (dir + 3) % 4;
    }
    else if (cmd[i] == 'F') {
      map[x][y] = 1;
      y += dx[dir];
      x += dy[dir];

      if (y > r)
        r = y;
      if (y < l)
        l = y;
      if (x > b)
        b = x;
      if (x < t)
        t = x;
      
      map[x][y] = 1;
    }
  }

  
  for (int i = t; i <= b; i++) {
    for (int j = l; j <= r; j++) {
      if (map[i][j] == 1)
        cout << ".";
      else
        cout << "#";
    }
    cout << "\n";
  }
  
  return 0;
}