/***** award link *****/
/* http://codility.com/cert/view/cert3HH6NF-M8W33NANRNWUPP9C/ */
/*********************/

#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

vector<int> solution(vector<int> &A, vector<int> &B) {
  A.insert(A.begin(), 0);
  A.push_back(0);
  int n = A.size(), m = B.size(), minA = 100000, maxA = 0;
  int low[100001], high[100001];
  bzero(low, sizeof(low));
  bzero(high, sizeof(high));
  bool inc = false;
  for(int i = 1; i < n; i ++) {
    if(i != n-1) {
      maxA = max(maxA, A[i]);
      minA = min(minA, A[i]);
    }
    if(inc) {
      if(A[i] >= A[i-1]) continue;
      else {
        high[A[i-1]] += 1;
        inc = false;
      }
    } else {
      if(A[i] <= A[i-1]) continue;
      else {
        low[A[i-1]] += 1;
        inc = true;
      }
    }
  }
  low[0] += 1;
  for(int i = 1; i < 100001; i ++) {
    high[i] += high[i-1];
    low[i] += low[i-1];
  }
  vector<int> res;
  for(int i = 0; i < m; i ++) {
    if(B[i] > maxA) res.push_back(0);
    else res.push_back(low[B[i]] - high[B[i]] - 1);
  }
  return res;
}

int main() {
  int a[] = {0, 100000, 0, 100000, 0, 100000, 0};
  int b[] = {0, 1, 2, 99999, 3, 100000};
  vector<int> A, B;
  for(int i = 0; i < 7; i ++) A.push_back(a[i]);
  for(int i = 0; i < 6; i ++) B.push_back(b[i]);
  vector<int> ans = solution(A, B);
  for(int i = 0; i < ans.size(); i ++) cout << ans[i] << endl;
  return 0;
}
