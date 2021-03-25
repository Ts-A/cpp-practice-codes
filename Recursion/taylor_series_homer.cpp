#include <iostream>
#include "local_functions.h"

namespace local{
  double taylor_homer(int, int);
}

int main() {
  int x, n;
  cout << "\nEnter numbers for taylors_series(x, n) where x is an integer and n is a whole number:";
  cin >> x >> n;
  double result = local::taylor_homer(x, n);
  cout << '\n' << result << endl;
  return 0;
}

double local::taylor_homer(int x, int n) {
  static float y = 1;
  if(y == n) return 1;
  return 1 + (x / y++) * (taylor_homer(x, n));
}

