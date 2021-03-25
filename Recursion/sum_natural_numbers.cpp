#include <iostream>

#define cout std::cout
#define cin std::cin
#define endl std::endl

int sum(int n) {
  return n > 1 ? n + sum(n-1) : 1;
}

int main() {
  int n;
  cout << "\nEnter a natural number n:";
  cin >> n;
  cout << "/nSum of n natural numbers:" << sum(n) << endl;
  return 0;
}