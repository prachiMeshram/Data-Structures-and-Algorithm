// https://www.codingninjas.com/studio/problems/1062679?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0


// OPTIMISED APPROACH
// return 1 if == m
// return 2 if > m
// return 0 if < m
int func (int mid, int n, int m) {
  long long ans = 1;
  for (int i = 1; i <= n; i++) {
    ans = ans*mid ;
    if (ans > m) {
      return 2;
    }
  }
  if (ans == m) {
    return 1;
  }
  return 0;
}
int NthRoot(int n, int m) {
  // Write your code here.
  int s = 1;
  int e = m;
  while (s <= e) {
    int mid = s + (e-s)/2;
    int midN = func(mid, n, m);
    if (midN == 1) {
      return mid;
    }
    else if (midN == 2) {
      e = mid-1;
    }
    else {
      s = mid + 1;
    }
  }

  return -1;
}