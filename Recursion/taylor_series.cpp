#include <iostream>
#include "local_functions.h"

#define cout std::cout
#define cin std::cin
#define endl std::endl

namespace local{
  double taylor_series(int, int);
}

int main() {
  int x, n;
  cout << "\nEnter numbers for taylors_series(x, n) where x is an integer and n is a whole number:";
  cin >> x >> n;
  double result = local::taylor_series(x, n);
  cout << '\n' << result << endl;
  return 0;
}

double local::taylor_series(int x, int n) {
  if(n == 0) {
    cout << "1";
    return 1;
  }
  double r = local::taylor_series(x, n - 1);
  cout << " + (" << x << " ^ " << n << ") / " << n << "!";
  return r + ((float)power(x, n) / factorial(n));
}