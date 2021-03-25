#include <iostream>

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define string std::string

int combination(int n, int r) {
  if(r == 0 || r == n) return 1;
  return combination(n - 1, r - 1) + combination(n - 1, r);
}

int factorial(int n) {
  return n > 1 ? n * factorial(n - 1) : 1;
}

int fibonacci(int n) {
  static int *fibonacci_memory = new int[n + 1];
  if(n < 0) return -1;
  else if(n <= 1) return n;
  else {
    if(!fibonacci_memory[n]) fibonacci_memory[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return fibonacci_memory[n];
  }
}

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

int sum(int n) {
  return n > 1 ? n + sum(n-1) : 1;
}

double taylor_series(int x, int n) {
  if(n == 0) {
    cout << "1";
    return 1;
  }
  double r = taylor_series(x, n - 1);
  cout << " + (" << x << " ^ " << n << ") / " << n << "!";
  return r + ((float)power(x, n) / factorial(n));
}

double taylor_homer(int x, int n) {
  static float y = 1;
  if(y == n) return 1;
  return 1 + (x / y++) * (taylor_homer(x, n));
}

void tower_of_hanoi(int disk, string tower_A, string tower_B, string tower_C) {
  if(disk == 1) cout << "\nMove disk " << disk << " from " << tower_A << " to " << tower_C << endl;
  else {
    tower_of_hanoi(disk - 1, tower_A, tower_C, tower_B);
    cout << "\nMove disk " << disk << " from " << tower_A << " to " << tower_C << endl;
    tower_of_hanoi(disk - 1, tower_B, tower_A, tower_C);
  }
}