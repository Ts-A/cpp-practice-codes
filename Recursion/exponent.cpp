#include <iostream>

#define cout std::cout
#define cin std::cin
#define endl std::endl

int power(int m, int n) {
  if(n > 0) {
    if(n % 2 == 0) {
      return power(m * m, n / 2);
    } else {
      return m * power(m * m, (n - 1) / 2);
    }
  } else {
    return 1;
  }
}

int main() {
  int m, n;
  cout << "\nEnter (m, n) to find m ^ n:";
  cin >> m >> n;
  cout << "\n" << m << " ^ " << n << " = " << power(m, n) << endl;
  return 0;
}