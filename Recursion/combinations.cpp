#include <iostream>

#define cout std::cout
#define cin std::cin
#define endl std::endl

int combination(int, int);

int main() {
  int n, r;
  cout << "\nEnter (n, r) such that n, r are non-negative integers, r <= n:";
  cin >> n >> r;
  cout << "\nnCr: " << combination(n, r) << endl;
  return 0;
}

int combination(int n, int r) {
  if(r == 0 || r == n) return 1;
  return combination(n - 1, r - 1) + combination(n - 1, r);
}