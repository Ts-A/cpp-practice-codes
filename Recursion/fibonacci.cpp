#include <iostream>

#define cout std::cout
#define cin std::cin
#define endl std::endl

int fibonacci(int);

int main() {
  int n;
  cout << "\nEnter a whole number n:";
  cin >> n;
  cout << "\nnth fibonnaci term is: " << fibonacci(n) << endl;
  return 0;
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