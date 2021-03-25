#include <iostream>

#define cout std::cout
#define cin std::cin
#define endl std::endl

int factorial(int n) {
  return n > 1 ? n * factorial(n - 1) : 1;
}

int main() {
  int n;
  cout << "\nEnter a whole number n:";
  cin >> n;
  cout << "\n" << n << "!" << " = " << factorial(n) << endl;
  return 0;
}