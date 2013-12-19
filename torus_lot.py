def max_subarray(a, l):
  current, ans, start  = 0, 0, -1
  for i in range(0, len(a)):
    if i - start == l + 1:
      start += 1
      current -= a[start]
      while a[start + 1] < 0 and start + 1 < i:
        start += 1
        current -= a[start]
    if current < 0:
      start = i - 1
      current = a[i]
    else:
      current += a[i] 
    ans = max(current, ans)
  return ans

def solution(C):
  m, n = len(C), len(C[0])
  p = []
  sumX = []
  for i in range(201):
    p.append([0]*201)
    sumX.append([0]*201)
  ans, current = 0, 0
  for i in range(1, 2*m+1):
    for j in range(1, 2*n+1):
      p[i][j] = C[(i-1)%m][(j-1)%n]
      sumX[i][j] = sumX[i][j-1] + p[i][j];
  for left in range(1, n+1):
    for right in range(left, left + n):
      a = [0] * 201;
      for i in range(1, 2*m+1):
        a[i] = sumX[i][right] - sumX[i][left - 1]
      ans = max(ans, max_subarray(a[1:2*m+1], m))
  return ans

C = [[1, -1, 2], [-1, -1, -1], [3, -1, 4]]
print solution(C)
