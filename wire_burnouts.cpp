/***** score *****/
/*     100/100   */
/*****************/

#include<vector>
#include<queue>
#include<iostream>
#include<cstring>
using namespace std;

typedef pair<int, int> PII;
bool check(int edge[800][800], int t, int N) {
  queue<PII> q;
  q.push(PII(0, 0));
  bool visit[400][400];
  bzero(visit, sizeof(visit));
  visit[0][0] = true;
  while(!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop();
    if(x == N - 1 && y == N - 1) return true;
    int dirX[] = {0, 0, -1, 1}, dirY[] = {-1, 1, 0, 0};
    for(int i = 0; i < 4; i ++) {
      int newX = dirX[i] + x, newY = dirY[i] + y;
      if(newX < 0 || newX > N-1 || newY < 0 || newY > N-1) continue;
      if(!visit[newX][newY] && edge[newX + x][newY + y] > t) {
        q.push(PII(newX, newY));
        visit[newX][newY] = true;
      }
    }
  }
  return false;
}

int solution(int N, const vector<int> &A, const vector<int> &B, const vector<int> &C) {
  int edge[800][800], inf = 320000, M = A.size();
  for(int i = 0; i < N; i ++) {
    for(int j = 0; j < N; j ++) {
      if(i < N - 1) edge[2*i+1][2*j] = 320000;
      if(j < N - 1) edge[2*i][2*j+1] = 320000;
    }
  }
  for(int i = 0; i < M; i ++) {
    int x1 = A[i], y1 = B[i], x2 = C[i] ? x1 + 1 : x1, y2 = C[i] ? y1 : y1 + 1;
    edge[x1+x2][y1+y2] = min(i, edge[x1+x2][y1+y2]);
  }
  int left = 0, right = M-1;
  while(left < right) {
    int mid = (left + right)/2;
    cout << left << " " << right << " " << mid << check(edge, mid, N) << endl;
    if(check(edge, mid, N)) left = mid + 1;
    else right = mid;
  }
  if(check(edge, left, N)) return -2;
  else return left;
}

int main() {
  int a[] = {0, 1, 1, 2, 3, 2, 1, 0, 0};
  int b[] = {0, 1, 1, 1, 2, 2, 3, 1, 0};
  int c[] = {0, 1, 0, 0, 0, 1, 1, 0, 1};
  int m = 1;
  vector<int> A, B, C;
  for(int i = 0; i < m; i ++) {
    A.push_back(a[i]);
    B.push_back(b[i]);
    C.push_back(c[i]);
  }
  cout << solution(4, A, B, C) + 1 << endl;
}
