#include <iostream>

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define string std::string

void tower_of_hanoi(int disk, string tower_A, string tower_B, string tower_C) {
  if(disk == 1) cout << "\nMove disk " << disk << " from " << tower_A << " to " << tower_C << endl;
  else {
    tower_of_hanoi(disk - 1, tower_A, tower_C, tower_B);
    cout << "\nMove disk " << disk << " from " << tower_A << " to " << tower_C << endl;
    tower_of_hanoi(disk - 1, tower_B, tower_A, tower_C);
  }
}

int main() {
  int disk;
  cout << "\nEnter number of disks to move from tower A to C using B:";
  cin >> disk;
  tower_of_hanoi(disk, "Tower A", "Tower B", "Tower C");
  return 0;
}